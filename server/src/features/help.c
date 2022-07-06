/*
** EPITECH PROJECT, 2021
** B-NWP-400-NAN-4-1-myteams-victor.harri-chal
** File description:
** help.c
*/

#include "server.h"

int help(client_t *clients, int i, char **command)
{
    clients[i].is_unknown_cmd = false;
    if (command[1] != NULL) {
        dprintf(clients[i].socket, "%s", INVALID_FORMAT);
        return 1;
    }
    dprintf(clients[i].socket, "%s", HELP_CMD);
    return 0;
}
