/*
** EPITECH PROJECT, 2021
** B-NWP-400-NAN-4-1-myteams-victor.harri-chal
** File description:
** use.c
*/

#include "server.h"

int use(server_t *server, client_t *clients, int i, char **command)
{
    clients[i].is_unknown_cmd = false;
    if (command[2] != NULL || command[1] == NULL) {
        return use_without_args(clients, i);
    }
    if (!check_quotes(command[1])) {
        dprintf(clients[i].socket, "%s", INVALID_FORMAT);
        return 1;
    }
    char *object_uuid = remove_quotes(command[1]);
    return check_emplacement(object_uuid, server, clients, i);
}

int use_without_args(client_t *clients, int i)
{
    clients[i].emplacement = ROOT;
    return 0;
}

int check_emplacement(char *object_uuid, server_t *server,
client_t *clients, int i)
{
    if (!read_sub_team_and_user_uuid(object_uuid, clients[i].uuid,
        server->teams_list) && (clients[i].emplacement == ROOT)) {
        dprintf(clients[i].socket, "%s", PERMISSION_DENIED);
        return 1;
    }
    if (clients[i].emplacement == ROOT) {
        check_uuid_team(object_uuid, server, clients, i);
        return 0;
    }
    if (clients[i].emplacement == TEAM) {
        check_uuid_channel(object_uuid, server, clients, i);
        return 0;
    }
    if (clients[i].emplacement == CHANNEL) {
        check_uuid_thread(object_uuid, server, clients, i);
        return 0;
    }
    return 1;
}
