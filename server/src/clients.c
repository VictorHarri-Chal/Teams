/*
** EPITECH PROJECT, 2022
** myTeams
** File description:
** clients
*/

#include "server.h"

void handle_clients_inputs(client_t *clients, server_t *server)
{
    for (int i = 0; i < clients[i].socket && max_clients != 0; i++) {
        if (FD_ISSET(clients[i].socket, &server->rfd))
            check_commands(clients, server, i);
    }
}

void check_commands(client_t *clients, server_t *server, int i)
{
    init_str(clients, i);
    int ret = read(clients[i].socket, clients[i].rbuf, 1024);
    if (ret == -1 || ret == 0)
        return;
    clients[i].rbuf[strlen(clients[i].rbuf) + 1] = '\0';
    login_command_or_not(clients, server, i);
}
