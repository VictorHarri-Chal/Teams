/*
** EPITECH PROJECT, 2021
** B-NWP-400-NAN-4-1-myteams-victor.harri-chal
** File description:
** info.c
*/

#include "server.h"

int info(client_t *clients, int i, char **command, server_t *server)
{
    clients[i].is_unknown_cmd = false;
    if (command[1] != NULL) {
        dprintf(clients[i].socket, "%s", INVALID_FORMAT);
        return 1;
    }
    if (clients[i].emplacement == ROOT)
        check_info_user(clients, i);
    if (clients[i].emplacement == TEAM)
        check_info_team(clients, i, server);
    if (clients[i].emplacement == CHANNEL)
        check_info_channel(clients, i, server);
    if (clients[i].emplacement == THREAD)
        check_info_thread(clients, i, server);
    return 0;
}

int check_info_user(client_t *clients, int i)
{
    dprintf(clients[i].socket, "%s %s \"%s\" %d", PRINT_INFO_USER,
        clients[i].uuid, clients[i].user_name,
        clients[i].logged_in);
    return 0;
}

int check_info_team(client_t *clients, int i, server_t *server)
{
    team_t *team = return_team_from_uuid(clients[i].emplacement_uuid, server);
    dprintf(clients[i].socket, "%s %s \"%s\" \"%s\"", PRINT_INFO_TEAM,
        team->uuid, team->name, team->description);
    return 0;
}

int check_info_channel(client_t *clients, int i, server_t *server)
{
    channel_t *channel = return_channel_from_team(clients[i].emplacement_uuid,
        server);
    dprintf(clients[i].socket, "%s %s \"%s\" \"%s\"", PRINT_INFO_CHANNEL,
        channel->uuid, channel->name, channel->description);
    return 0;
}

int check_info_thread(client_t *clients, int i, server_t *server)
{
    thread_t *thread = return_thread_from_team(clients[i].emplacement_uuid,
        server);
    dprintf(clients[i].socket, "%s %s %s %ld \"%s\" \"%s\"", PRINT_INFO_THREAD,
        thread->uuid, thread->creator_uuid, thread->timestamp, thread->title,
        thread->message);
    return 0;
}
