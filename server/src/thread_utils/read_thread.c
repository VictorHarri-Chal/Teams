/*
** EPITECH PROJECT, 2021
** B-NWP-400-NAN-4-1-myteams-victor.harri-chal
** File description:
** thread_check_name.c
*/

#include "server.h"

bool read_thread_uuid(char *uuid, channel_t *channel)
{
    LIST_FOREACH(channel->threads_list, &channel->thread_head, next_thread) {
        if (strcmp(uuid, channel->threads_list->uuid) == 0) {
            return true;
        }
    }
    return false;
}

thread_t *return_thread_from_uuid(char *uuid, channel_t *channel)
{
    LIST_FOREACH(channel->threads_list, &channel->thread_head, next_thread) {
        if (strcmp(uuid, channel->threads_list->uuid) == 0) {
            return channel->threads_list;
        }
    }
    return NULL;
}

bool read_thread_name(char *name, channel_t *channel)
{
    LIST_FOREACH(channel->threads_list, &channel->thread_head, next_thread) {
        if (strcmp(name, channel->threads_list->title) == 0) {
            return true;
        }
    }
    return false;
}
