/*
** EPITECH PROJECT, 2021
** B-NWP-400-NAN-4-1-myteams-victor.harri-chal
** File description:
** user.c
*/

#include "server.h"

int user(client_t *clients, int i, char **command)
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
    char *user_uuid = remove_quotes(command[1]);
    return (user_action(clients, i, user_uuid));
}

int user_action(client_t *clients, int i, char *user_uuid)
{
    if (strcmp(clients[i].uuid, user_uuid) == 0) {
        dprintf(clients[i].socket, "%s %s", UUID_NOT_FOUND, user_uuid);
        return 1;
    }
    int receiver = read_user(clients, user_uuid);
    if (receiver == 31) {
        dprintf(clients[i].socket, "%s %s", UUID_NOT_FOUND, user_uuid);
        return 1;
    }
    dprintf(clients[i].socket, "%s %s \"%s\" %d", PRINT_INFO_USER,
        clients[receiver].uuid, clients[receiver].user_name,
        clients[receiver].logged_in);
    return 0;
}
