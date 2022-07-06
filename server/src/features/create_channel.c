/*
** EPITECH PROJECT, 2021
** B-NWP-400-NAN-4-1-myteams-victor.harri-chal
** File description:
** create_channel.c
*/

#include "server.h"

int check_create_channel(server_t *server, client_t *clients, int i,
char **command)
{
    if (command[3] != NULL || command[1] == NULL || command[2] == NULL) {
        dprintf(clients[i].socket, "%s", INVALID_FORMAT);
        return 1;
    }
    if (!check_quotes(command[1]) || !check_quotes(command[2])) {
        dprintf(clients[i].socket, "%s", INVALID_FORMAT);
        return 1;
    }
    char *channel_name = remove_quotes(command[1]);
    char *channel_desc = remove_quotes(command[2]);
    if (read_channel_name(channel_name, server->teams_list)) {
        dprintf(clients[i].socket, "%s", ALREADY_EXIST);
        return 1;
    }
    if (channel_arg_parsing(clients, i, channel_name, channel_desc) == 1)
        return 1;
    channel_t *new_channel = create_channel(channel_name, channel_desc,
        server->teams_list);
    create_channel_action(clients, i , new_channel, server);
    return 0;
}

int channel_arg_parsing(client_t *clients, int i, char *channel_name,
char *channel_desc)
{
    if (strlen(channel_name) > MAX_NAME_LENGTH) {
        dprintf(clients[i].socket, "%s", NAME_TOO_LONG);
        return 1;
    }
    if (strlen(channel_desc) > MAX_DESCRIPTION_LENGTH) {
        dprintf(clients[i].socket, "%s", DESC_TOO_LONG);
        return 1;
    }
    return 0;
}

void create_channel_action(client_t *clients, int i, channel_t *new_channel,
server_t *server)
{
    server_event_channel_created(server->teams_list->uuid, new_channel->uuid,
        new_channel->name);
    for (int j = 0; j < 30; j++) {
        if (clients[j].logged_in && read_sub_user_uuid(clients[j].uuid,
            server->teams_list))
            channel_send_event_to_client(clients, j, i, new_channel);
    }
}

void channel_send_event_to_client(client_t *clients, int j, int i,
channel_t *new_channel)
{
    if (j == i) {
        dprintf(clients[j].socket, "%s %s \"%s\" \"%s\" %s",
            PRINT_CHANNEL_CREATED, new_channel->uuid, new_channel->name,
            new_channel->description, EVENT_CHANNEL_CREATED);
    } else {
        dprintf(clients[j].socket, "%s %s \"%s\" \"%s\"",
            EVENT_CHANNEL_CREATED, new_channel->uuid, new_channel->name,
            new_channel->description);
    }
}
