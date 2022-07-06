/*
** EPITECH PROJECT, 2021
** B-NWP-400-NAN-4-1-myteams-victor.harri-chal
** File description:
** use_check_uuid.c
*/

#include "server.h"

void check_uuid_team(char *object_uuid, server_t *server,
client_t *clients, int i)
{
    if (read_team_uuid(object_uuid, server)) {
        clients[i].emplacement_uuid = object_uuid;
        clients[i].emplacement = TEAM;
    }
}

void check_uuid_channel(char *object_uuid, server_t *server,
client_t *clients, int i)
{
    if (read_channel_from_team(object_uuid, server)) {
        clients[i].emplacement_uuid = object_uuid;
        clients[i].emplacement = CHANNEL;
    }
}

void check_uuid_thread(char *object_uuid, server_t *server,
client_t *clients, int i)
{
    if (read_thread_from_team(object_uuid, server)) {
        clients[i].emplacement_uuid = object_uuid;
        clients[i].emplacement = THREAD;
    }
}
