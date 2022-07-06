/*
** EPITECH PROJECT, 2021
** B-NWP-400-NAN-4-1-myteams-victor.harri-chal
** File description:
** login.c
*/

#include "server.h"

int login(client_t *clients, int i, char **command)
{
    clients[i].is_unknown_cmd = false;
    if (command[2] != NULL || command[1] == NULL) {
        dprintf(clients[i].socket, "%s", INVALID_FORMAT);
        return 1;
    }
    if (!check_quotes(command[1])) {
        dprintf(clients[i].socket, "%s", INVALID_FORMAT);
        return 1;
    }
    char *username = remove_quotes(command[1]);
    if (strlen(username) > MAX_NAME_LENGTH) {
        dprintf(clients[i].socket, "%s", NAME_TOO_LONG);
        return 1;
    }
    create_user(clients, i, username);
    return 0;
}
