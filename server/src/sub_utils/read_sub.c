/*
** EPITECH PROJECT, 2022
** myteams
** File description:
** read_subscribed
*/

#include "server.h"

bool read_sub_team_and_user_uuid(char *team_uuid, char *user_uuid, team_t *team)
{
    LIST_FOREACH(team->sub_list, &team->sub_head, next_sub) {
        if (strcmp(team_uuid, team->sub_list->team_uuid) == 0 &&
        strcmp(user_uuid, team->sub_list->user_uuid) == 0)
            return true;
    }
    return false;
}

bool read_sub_team_uuid(char *team_uuid, team_t *team)
{
    LIST_FOREACH(team->sub_list, &team->sub_head, next_sub) {
        if (strcmp(team_uuid, team->sub_list->team_uuid) == 0)
            return true;
    }
    return false;
}

bool read_sub_user_uuid(char *user_uuid, team_t *team)
{
    LIST_FOREACH(team->sub_list, &team->sub_head, next_sub) {
        if (strcmp(user_uuid, team->sub_list->user_uuid) == 0)
            return true;
    }
    return false;
}
