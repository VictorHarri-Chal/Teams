/*
** EPITECH PROJECT, 2022
** myteams
** File description:
** subscribed
*/

#include "server.h"

int subscribed(client_t *clients, int i, char **command)
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
    char *object_uuid = remove_quotes(command[1]);
    (void) object_uuid;
    dprintf(clients[i].socket, "%s", CMD_OK);
    return 0;
}
