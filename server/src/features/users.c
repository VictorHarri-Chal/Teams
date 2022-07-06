/*
** EPITECH PROJECT, 2021
** B-NWP-400-NAN-4-1-myteams-victor.harri-chal
** File description:
** users.c
*/

#include "server.h"

int users(client_t *clients, int i, char **command)
{
    clients[i].is_unknown_cmd = false;
    if (command[1] != NULL) {
        dprintf(clients[i].socket, "%s", INVALID_FORMAT);
        return 1;
    }
    fill_users_file(clients);
    dprintf(clients[i].socket, "%s", PRINT_USERS);
    return 0;
}

void fill_users_file(client_t *clients)
{
    FILE *fp;

    fp = fopen("users/users.txt", "w+");
    for (int i = 0; i < 30; i++) {
        if ((strcmp(clients[i].uuid, "") != 0) &&
        (strcmp(clients[i].user_name, "") != 0)) {
            fprintf(fp, "\"%s\" \"%s\" \"%d\"\n", clients[i].uuid,
            clients[i].user_name, clients[i].logged_in);
        }
    }
    fclose(fp);
}
