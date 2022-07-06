/*
** EPITECH PROJECT, 2021
** B-NWP-400-NAN-4-1-myteams-victor.harri-chal
** File description:
** create_thread.c
*/

#include "server.h"

int check_create_thread(server_t *server, client_t *clients, int i,
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
    char *thread_title = remove_quotes(command[1]);
    char *thread_body = remove_quotes(command[2]);
    if (read_thread_name(thread_title, server->teams_list->channels_list)) {
        dprintf(clients[i].socket, "%s", ALREADY_EXIST);
        return 1;
    }
    if (thread_arg_parsing(clients, i, thread_title, thread_body) == 1)
        return 1;
    thread_t *new_thread = create_thread(thread_title, thread_body,
    server->teams_list->channels_list, clients[i].uuid);
    create_thread_action(clients, i, new_thread, server);
    return 0;
}

int thread_arg_parsing(client_t *clients, int i, char *thread_title,
char *thread_body)
{
    if (strlen(thread_title) > MAX_NAME_LENGTH) {
        dprintf(clients[i].socket, "%s", NAME_TOO_LONG);
        return 1;
    }
    if (strlen(thread_body) > MAX_BODY_LENGTH) {
        dprintf(clients[i].socket, "%s", BODY_TOO_LONG);
        return 1;
    }
    return 0;
}

void create_thread_action(client_t *clients, int i, thread_t *new_thread,
server_t *server)
{
    server_event_thread_created(server->teams_list->channels_list->uuid,
    new_thread->uuid, clients[i].uuid, new_thread->title, new_thread->message);
    for (int j = 0; j < 30; j++) {
        if (clients[j].logged_in && read_sub_user_uuid(clients[j].uuid,
            server->teams_list)) {
            thread_send_event_to_client(clients, j, i, new_thread);
        }
    }
}

void thread_send_event_to_client(client_t *clients, int j, int i,
thread_t *new_thread)
{
    if (j == i) {
        dprintf(clients[j].socket, "%s %s %s %ld \"%s\" \"%s\" %s",
            PRINT_THREAD_CREATED, new_thread->uuid, clients[i].uuid,
            new_thread->timestamp, new_thread->title, new_thread->message,
            EVENT_THREAD_CREATED);
    } else {
        dprintf(clients[j].socket, "%s %s %s %ld \"%s\" \"%s\"",
            EVENT_THREAD_CREATED, new_thread->uuid, clients[i].uuid,
            new_thread->timestamp, new_thread->title,
            new_thread->message);
    }
}