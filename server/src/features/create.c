/*
** EPITECH PROJECT, 2021
** B-NWP-400-NAN-4-1-myteams-victor.harri-chal
** File description:
** create.c
*/

#include "server.h"

int create(server_t *server, client_t *clients, int i, char **command)
{
    clients[i].is_unknown_cmd = false;
    if (clients[i].emplacement == ROOT)
        check_create_team(server, clients, i, command);
    if (clients[i].emplacement == TEAM)
        check_create_channel(server, clients, i, command);
    if (clients[i].emplacement == CHANNEL)
        check_create_thread(server, clients, i, command);
    if (clients[i].emplacement == THREAD)
        check_create_reply(server, clients, i, command);
    return 0;
}
