/*
** EPITECH PROJECT, 2021
** B-NWP-400-NAN-4-1-myteams-victor.harri-chal
** File description:
** logout.c
*/

#include "server.h"

int logout(client_t *clients, int i, char **command)
{
    clients[i].is_unknown_cmd = false;
    if (command[1] != NULL) {
        dprintf(clients[i].socket, "%s", INVALID_FORMAT);
        return 1;
    }
    server_event_user_logged_out(clients[i].uuid);
    for (int j = 0; j < 30; j++) {
        if (clients[j].logged_in) {
            if (j == i) {
                dprintf(clients[j].socket, "%s %s \"%s\" %s",
                EVENT_DISCONNECTED_USER, clients[i].uuid,
                clients[i].user_name, KILL_CLIENT);
            } else {
                dprintf(clients[j].socket, "%s %s \"%s\"",
                    EVENT_DISCONNECTED_USER, clients[i].uuid,
                    clients[i].user_name);
            }
        }
    }
    clients[i].logged_in = false;
    return 0;
}
