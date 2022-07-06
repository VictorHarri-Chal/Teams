/*
** EPITECH PROJECT, 2021
** B-NWP-400-NAN-4-1-myteams-victor.harri-chal
** File description:
** messages.c
*/

#include "server.h"

int messages(client_t *clients, int i, char **command)
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
    return (messages_action(clients, i, user_uuid));
}

int messages_action(client_t *clients, int i, char *user_uuid)
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
    dprintf(clients[i].socket,
        "%s discussions/%d-%d.txt discussions/%d-%d.txt",
        PRINT_PRIVATE_MSGS, i, receiver, receiver, i);
    return 0;
}
