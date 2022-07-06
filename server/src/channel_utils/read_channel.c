/*
** EPITECH PROJECT, 2021
** B-NWP-400-NAN-4-1-myteams-victor.harri-chal
** File description:
** channel_check_name.c
*/

#include "server.h"

bool read_channel_uuid(char *uuid, team_t *team)
{
    LIST_FOREACH(team->channels_list, &team->channel_head, next_channel) {
        if (strcmp(uuid, team->channels_list->uuid) == 0) {
            return true;
        }
    }
    return false;
}

channel_t *return_channel_from_uuid(char *uuid, team_t *team)
{
    LIST_FOREACH(team->channels_list, &team->channel_head, next_channel) {
        if (strcmp(uuid, team->channels_list->uuid) == 0) {
            return team->channels_list;
        }
    }
    return NULL;
}

bool read_channel_name(char *name, team_t *team)
{
    LIST_FOREACH(team->channels_list, &team->channel_head, next_channel) {
        if (strcmp(name, team->channels_list->name) == 0) {
            return true;
        }
    }
    return false;
}
