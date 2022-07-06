/*
** EPITECH PROJECT, 2021
** B-NWP-400-NAN-4-1-myteams-victor.harri-chal
** File description:
** list.c
*/

#include "server.h"

int list(client_t *clients, int i, char **command)
{
    clients[i].is_unknown_cmd = false;
    if (command[1] != NULL) {
        dprintf(clients[i].socket, "%s", INVALID_FORMAT);
        return 1;
    }
    if (clients[i].emplacement == ROOT)
        check_list_team(clients, i);
    if (clients[i].emplacement == TEAM)
        check_list_channel(clients, i);
    if (clients[i].emplacement == CHANNEL)
        check_list_thread(clients, i);
    if (clients[i].emplacement == THREAD)
        check_list_reply(clients, i);
    return 0;
}

int check_list_team(client_t *clients, int i)
{
    dprintf(clients[i].socket, "%s", CMD_OK);
    return 0;
}

int check_list_channel(client_t *clients, int i)
{
    dprintf(clients[i].socket, "%s", CMD_OK);
    return 0;
}

int check_list_thread(client_t *clients, int i)
{
    dprintf(clients[i].socket, "%s", CMD_OK);
    return 0;
}

int check_list_reply(client_t *clients, int i)
{
    dprintf(clients[i].socket, "%s", CMD_OK);
    return 0;
}
