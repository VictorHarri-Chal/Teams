/*
** EPITECH PROJECT, 2022
** myteams
** File description:
** reply
*/

#include "server.h"

reply_t *init_reply(thread_t *thread)
{
    return thread->replies_list;
}

reply_t *create_reply(char body[MAX_BODY_LENGTH], thread_t *thread)
{
    uuid_t uuid;

    thread->replies_list = malloc(sizeof(reply_t));
    if (!thread->replies_list)
        pterror("Reply malloc()");
    thread->replies_list->timestamp = time(NULL);
    strcpy(thread->replies_list->body, body);
    uuid_generate(uuid);
    uuid_unparse(uuid, thread->replies_list->uuid);
    return thread->replies_list;
}

reply_t *read_reply(char *uuid, thread_t *thread)
{
    LIST_FOREACH(thread->replies_list, &thread->reply_head, next_reply) {
        if (strcmp(uuid, thread->replies_list->uuid) == 0)
            return thread->replies_list;
    }
    return NULL;
}

char *get_reply_team_uuid(char *uuid_thread, server_t *server)
{
    LIST_FOREACH(server->teams_list, &server->team_head, next_team) {
        LIST_FOREACH(server->teams_list->channels_list,
        &server->teams_list->channel_head, next_channel) {
            LIST_FOREACH(server->teams_list->channels_list->threads_list,
            &server->teams_list->channels_list->thread_head, next_thread) {
                if (strcmp(uuid_thread,
                server->teams_list->channels_list->threads_list->uuid) == 0) {
                    return server->teams_list->uuid;
                }
            }
        }
    }
    return NULL;
}
