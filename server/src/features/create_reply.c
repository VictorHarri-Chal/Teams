/*
** EPITECH PROJECT, 2021
** B-NWP-400-NAN-4-1-myteams-victor.harri-chal
** File description:
** create_reply.c
*/

#include "server.h"

int check_create_reply(server_t *server, client_t *clients, int i,
char **command)
{
    if (command[2] != NULL || command[1] == NULL) {
        dprintf(clients[i].socket, "%s", INVALID_FORMAT);
        return 1;
    }
    if (!check_quotes(command[1])) {
        dprintf(clients[i].socket, "%s", INVALID_FORMAT);
        return 1;
    }
    char *reply_body = remove_quotes(command[1]);
    if (strlen(reply_body) > MAX_BODY_LENGTH) {
        dprintf(clients[i].socket, "%s", BODY_TOO_LONG);
        return 1;
    }
    reply_t *new_reply = create_reply(reply_body,
    server->teams_list->channels_list->threads_list);
    create_reply_action(clients, i, new_reply, server);
    return 0;
}

void create_reply_action(client_t *clients, int i, reply_t *new_reply,
server_t *server)
{
    server_event_reply_created(
        server->teams_list->channels_list->threads_list->uuid,
        clients[i].uuid, new_reply->body);
    for (int j = 0; j < 30; j++) {
        if (clients[j].logged_in &&
            read_sub_user_uuid(clients[j].uuid, server->teams_list))
            reply_send_event_to_client(clients, j, i, new_reply, server);
    }
}

void reply_send_event_to_client(client_t *clients, int j, int i,
reply_t *new_reply, server_t *server)
{
    if (j == i) {
        dprintf(clients[j].socket, "%s %s %s %ld \"%s\" %s %s",
            PRINT_REPLY_CREATED,
            server->teams_list->channels_list->threads_list->uuid,
            clients[i].uuid, new_reply->timestamp, new_reply->body,
            EVENT_THREAD_REPLY_RCV, get_reply_team_uuid(
            server->teams_list->channels_list->threads_list->uuid,
            server));
    } else {
        dprintf(clients[j].socket, "%s %s %s %s \"%s\"",
            EVENT_THREAD_REPLY_RCV, get_reply_team_uuid(
            server->teams_list->channels_list->threads_list->uuid,
            server),
            server->teams_list->channels_list->threads_list->uuid,
            clients[i].uuid, new_reply->body);
    }
}
