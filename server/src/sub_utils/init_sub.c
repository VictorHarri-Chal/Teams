/*
** EPITECH PROJECT, 2022
** myteams
** File description:
** init_sub
*/

#include "server.h"

subscribed_t *init_sub(team_t *team)
{
    LIST_INIT(&team->sub_head);
    return team->sub_list;
}

char *create_sub(char *team_uuid, char *user_uuid, team_t *team)
{
    team->sub_list = malloc(sizeof(subscribed_t));
    if (!team->sub_list)
        pterror("Subscribed struct malloc()");
    memset(team->sub_list, 0, sizeof(subscribed_t));
    strcpy(team->sub_list->team_uuid, team_uuid);
    strcpy(team->sub_list->user_uuid, user_uuid);
    LIST_INSERT_HEAD(&team->sub_head, team->sub_list, next_sub);
    return team->sub_list->team_uuid;
}
