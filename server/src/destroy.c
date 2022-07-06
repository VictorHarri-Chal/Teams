/*
** EPITECH PROJECT, 2022
** myteams
** File description:
** destroy
*/

#include "server.h"

void destroy_sub(server_t *server)
{
    LIST_FOREACH(server->teams_list->sub_list,
    &server->teams_list->sub_head, next_sub) {
        LIST_REMOVE(server->teams_list->sub_list, next_sub);
    }

}

void destroy_objects(server_t *server)
{
    LIST_FOREACH(server->teams_list, &server->team_head, next_team) {
        LIST_FOREACH(server->teams_list->channels_list, &server->teams_list->
        channel_head, next_channel) {
            LIST_FOREACH(server->teams_list->channels_list->threads_list,
            &server->teams_list->channels_list->thread_head, next_thread) {
                LIST_FOREACH(server->teams_list->channels_list->threads_list->
                replies_list, &server->teams_list->channels_list->threads_list->
                reply_head, next_reply) {
                    LIST_REMOVE(server->teams_list->channels_list->
                    threads_list->replies_list, next_reply);
                }
                LIST_REMOVE(server->teams_list->channels_list->threads_list,
                next_thread);
            }
            LIST_REMOVE(server->teams_list->channels_list, next_channel);
        }
        destroy_sub(server);
        LIST_REMOVE(server->teams_list, next_team);
    }
}

void free_objects(server_t *server)
{
    if (server->teams_list)
        free(server->teams_list);
    close(server->socket);
    free(server);
}

