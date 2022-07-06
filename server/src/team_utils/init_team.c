/*
** EPITECH PROJECT, 2022
** myteams
** File description:
** team
*/

#include "server.h"

team_t *init_team(server_t *server)
{
    LIST_INIT(&server->team_head);
    return server->teams_list;
}

team_t *create_team(char name[MAX_NAME_LENGTH],
char description[MAX_DESCRIPTION_LENGTH], server_t *server)
{
    uuid_t uuid;

    server->teams_list = malloc(sizeof(team_t));
    if (!server->teams_list)
        pterror("Team struct malloc()");
    server->teams_list->channels_list = init_channel(server->teams_list);
    server->teams_list->sub_list = init_sub(server->teams_list);
    strcpy(server->teams_list->name, name);
    strcpy(server->teams_list->description, description);
    uuid_generate(uuid);
    uuid_unparse(uuid, server->teams_list->uuid);
    LIST_INSERT_HEAD(&server->team_head, server->teams_list, next_team);
    return server->teams_list;
}
