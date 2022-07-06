/*
** EPITECH PROJECT, 2022
** myteams
** File description:
** core
*/

#include "server.h"

volatile bool *running = NULL;

void sigint_handler(int var)
{
    (void) var;
    *running = false;
}

void loop_server(client_t *clients, server_t *server)
{
    while (server->is_server_active) {
        add_sockets_to_set(clients, server);
        wait_for_activity_on_socket(clients, server);
    }
    clean_server(clients, server);
}

void add_sockets_to_set(client_t *clients, server_t *server)
{
    FD_ZERO(&server->rfd);
    FD_ZERO(&server->wfd);
    FD_SET(server->socket, &server->rfd);
    for (int i = 0; clients[i].socket != 0; i++)
        FD_SET(clients[i].socket, &server->rfd);
}

void wait_for_activity_on_socket(client_t *clients, server_t *server)
{
    server->activity = select(FD_SETSIZE, &server->rfd, &server->wfd, NULL,
    NULL);
    if (!server->is_server_active)
        return;
    if ((server->activity < 0) && (errno != EINTR))
        pterror("Select()");
    accept_client(clients, server);
    handle_clients_inputs(clients, server);
}

void accept_client(client_t *clients, server_t *server)
{
    int i = 0;
    int client_fd;

    if (FD_ISSET(server->socket, &server->rfd)) {
        client_fd = accept(server->socket, (struct sockaddr *)&server->addr,
        (socklen_t *) &server->len);
        if (client_fd < 0) {
            printf("%s\n", strerror(errno));
            pterror("Accept()");
        }
        for (; i < clients[i].socket && max_clients - 1 != 0; i++);
        clients[i].socket = client_fd;
        clients[i].is_init = true;
        init_str(clients, i);
    }
}
