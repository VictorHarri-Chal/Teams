/*
** EPITECH PROJECT, 2022
** myteams
** File description:
** user
*/

#include "server.h"

void create_user(client_t *clients, int i, char username[MAX_NAME_LENGTH])
{
    uuid_t uuid;

    uuid_generate(uuid);
    uuid_unparse(uuid, clients[i].uuid);
    strcpy(clients[i].user_name, username);
    clients[i].logged_in = true;
    server_event_user_created(clients[i].uuid, clients[i].user_name);
    server_event_user_logged_in(clients[i].uuid);
    for (int j = 0; j < 30; j++) {
        if (clients[j].logged_in) {
            dprintf(clients[j].socket, "%s %s \"%s\"",
                EVENT_NEW_USER_LOGGED_IN, clients[i].uuid,
                clients[i].user_name);
        }
    }
}

int read_user(client_t *clients, char *uuid)
{
    for (int i = 0; i < 30; i++) {
        if (strcmp(clients[i].uuid, uuid) == 0) {
            return i;
        }
    }
    return 31;
}
