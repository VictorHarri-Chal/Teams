/*
** EPITECH PROJECT, 2022
** myteams
** File description:
** thread
*/

#include "server.h"

thread_t *init_thread(channel_t *channel)
{
    LIST_INIT(&channel->thread_head);
    return channel->threads_list;
}

thread_t *create_thread(char title[MAX_NAME_LENGTH],
char message[MAX_BODY_LENGTH], channel_t *channel, char *creator_uuid)
{
    uuid_t uuid;

    channel->threads_list = malloc(sizeof(thread_t));
    if (!channel->threads_list)
        return NULL;
    channel->threads_list->timestamp = time(NULL);
    channel->threads_list->replies_list = init_reply(channel->threads_list);
    uuid_generate(uuid);
    uuid_unparse(uuid, channel->threads_list->uuid);
    strcpy(channel->threads_list->title, title);
    strcpy(channel->threads_list->message, message);
    strcpy(channel->threads_list->creator_uuid, creator_uuid);
    LIST_INSERT_HEAD(&channel->thread_head,
        channel->threads_list, next_thread);
    return channel->threads_list;
}

bool read_thread_from_team(char *uuid, server_t *server)
{
    bool thread_exists = false;

    LIST_FOREACH(server->teams_list, &server->team_head, next_team) {
        LIST_FOREACH(server->teams_list->channels_list,
            &server->teams_list->channel_head, next_channel) {
            thread_exists = read_thread_uuid(uuid,
                server->teams_list->channels_list);
            if (thread_exists == true)
                return true;
        }
    }
    return false;
}

thread_t *return_thread_from_team(char *uuid, server_t *server)
{
    thread_t *thread;

    LIST_FOREACH(server->teams_list, &server->team_head, next_team) {
        LIST_FOREACH(server->teams_list->channels_list,
            &server->teams_list->channel_head, next_channel) {
            thread = return_thread_from_uuid(uuid,
                server->teams_list->channels_list);
            if (thread != NULL)
                return thread;
        }
    }
    return NULL;
}
