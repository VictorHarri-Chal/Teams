/*
** EPITECH PROJECT, 2021
** B-NWP-400-NAN-4-1-myteams-victor.harri-chal
** File description:
** team_check_name.c
*/

#include "server.h"

bool read_team_uuid(char *uuid, server_t *server)
{
    LIST_FOREACH(server->teams_list, &server->team_head, next_team) {
        if (strcmp(uuid, server->teams_list->uuid) == 0)
            return true;
    }
    return false;
}

team_t *return_team_from_uuid(char *uuid, server_t *server)
{
    LIST_FOREACH(server->teams_list, &server->team_head, next_team) {
        if (strcmp(uuid, server->teams_list->uuid) == 0)
            return server->teams_list;
    }
    return NULL;
}

bool read_team_name(char *name, server_t *server)
{
    LIST_FOREACH(server->teams_list, &server->team_head, next_team) {
        if (strcmp(name, server->teams_list->name) == 0)
            return true;
    }
    return false;
}
