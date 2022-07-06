/*
** EPITECH PROJECT, 2021
** B-NWP-400-NAN-4-1-myteams-victor.harri-chal
** File description:
** destroy_server.c
*/

#include "server.h"

void clean_server(client_t *clients, server_t *server)
{
    (void) server;
    for (int i = 0; i < 30; i++) {
        if (clients[i].is_init == true)
            dprintf(clients[i].socket, "%s", KILL_CLIENT);
    }
}
