/*
** EPITECH PROJECT, 2022
** myteams
** File description:
** channel
*/

#include "server.h"

channel_t *init_channel(team_t *team)
{
    LIST_INIT(&team->channel_head);
    return team->channels_list;
}

channel_t *create_channel(char name[MAX_NAME_LENGTH],
char description[MAX_DESCRIPTION_LENGTH], team_t *team)
{
    uuid_t uuid;

    team->channels_list = malloc(sizeof(channel_t));
    if (!team->channels_list)
        return NULL;
    memset(team->channels_list, 0, sizeof(channel_t));
    strcpy(team->channels_list->name, name);
    strcpy(team->channels_list->description, description);
    uuid_generate(uuid);
    uuid_unparse(uuid, team->channels_list->uuid);
    team->channels_list->threads_list = init_thread(team->channels_list);
    LIST_INSERT_HEAD(&team->channel_head, team->channels_list, next_channel);
    return team->channels_list;
}

bool read_channel_from_team(char *uuid, server_t *server)
{
    bool channel_exists = false;

    LIST_FOREACH(server->teams_list, &server->team_head, next_team) {
        channel_exists = read_channel_uuid(uuid, server->teams_list);
        if (channel_exists == true)
            return true;
    }
    return false;
}

channel_t *return_channel_from_team(char *uuid, server_t *server)
{
    channel_t *channel;

    LIST_FOREACH(server->teams_list, &server->team_head, next_team) {
        channel = return_channel_from_uuid(uuid, server->teams_list);
        if (channel != NULL)
            return channel;
    }
    return NULL;
}
