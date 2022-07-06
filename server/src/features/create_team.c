/*
** EPITECH PROJECT, 2021
** B-NWP-400-NAN-4-1-myteams-victor.harri-chal
** File description:
** create_team.c
*/

#include "server.h"

int check_create_team(server_t *server, client_t *clients, int i,
char **command)
{
    if (command[3] != NULL || command[1] == NULL || command[2] == NULL) {
        dprintf(clients[i].socket, "%s", INVALID_FORMAT);
        return 1;
    }
    if (!check_quotes(command[1]) || !check_quotes(command[2])) {
        dprintf(clients[i].socket, "%s", INVALID_FORMAT);
        return 1;
    }
    char *team_name = remove_quotes(command[1]);
    char *team_desc = remove_quotes(command[2]);
    if (read_team_name(team_name, server)) {
        dprintf(clients[i].socket, "%s", ALREADY_EXIST);
        return 1;
    }
    if (team_arg_parsing(clients, i, team_name, team_desc) == 1)
        return 1;
    team_t *new_team = create_team(team_name, team_desc, server);
    create_team_action(clients, i, new_team);
    return 0;
}

int team_arg_parsing(client_t *clients, int i, char *team_name,
char *team_desc)
{
    if (strlen(team_name) > MAX_NAME_LENGTH) {
        dprintf(clients[i].socket, "%s", NAME_TOO_LONG);
        return 1;
    }
    if (strlen(team_desc) > MAX_DESCRIPTION_LENGTH) {
        dprintf(clients[i].socket, "%s", DESC_TOO_LONG);
        return 1;
    }
    return 0;
}

void create_team_action(client_t *clients, int i, team_t *new_team)
{
    server_event_team_created(new_team->uuid, new_team->name, clients[i].uuid);
    for (int j = 0; j < 30; j++) {
        if (clients[j].logged_in)
            team_send_event_to_client(clients, j, i, new_team);
    }
}

void team_send_event_to_client(client_t *clients, int j, int i,
team_t *new_team)
{
    if (j == i) {
        dprintf(clients[j].socket,
            "%s %s \"%s\" \"%s\" %s", PRINT_TEAM_CREATED,
            new_team->uuid, new_team->name, new_team->description,
            EVENT_TEAM_CREATED);
    } else {
        dprintf(clients[j].socket, "%s %s \"%s\" \"%s\"",
            EVENT_TEAM_CREATED, new_team->uuid, new_team->name,
            new_team->description);
    }
}