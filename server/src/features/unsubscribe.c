/*
** EPITECH PROJECT, 2021
** B-NWP-400-NAN-4-1-myteams-victor.harri-chal
** File description:
** unsubscribe.c
*/

#include "server.h"

int unsubscribe(server_t *server, client_t *clients, int i, char **command)
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
    char *team_uuid = remove_quotes(command[1]);
    if (!read_team_uuid(team_uuid, server)) {
        dprintf(clients[i].socket, "%s %s", TEAM_UUID_NOT_FOUND, team_uuid);
        return 1;
    }
    delete_sub(team_uuid, clients[i].uuid, server->teams_list);
    server_event_user_unsubscribed(team_uuid, clients[i].uuid);
    dprintf(clients[i].socket, "%s %s %s", PRINT_USER_UNSUBSCRIBED,
        clients[i].uuid, team_uuid);
    return 0;
}
