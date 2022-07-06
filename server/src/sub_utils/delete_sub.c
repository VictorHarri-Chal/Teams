/*
** EPITECH PROJECT, 2022
** myteams
** File description:
** delete_sub
*/

#include "server.h"

void delete_sub(char *team_uuid, char *user_uuid, team_t *team)
{
    LIST_FOREACH(team->sub_list, &team->sub_head, next_sub) {
        if (strcmp(team_uuid, team->sub_list->team_uuid) == 0 &&
        strcmp(user_uuid, team->sub_list->user_uuid) == 0) {
            LIST_REMOVE(team->sub_list, next_sub);
            return;
        }
    }
    return;
}
