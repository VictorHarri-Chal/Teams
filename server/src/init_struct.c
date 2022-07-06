/*
** EPITECH PROJECT, 2022
** myTeams
** File description:
** init_server
*/

#include "server.h"

server_t *init_server(server_t *server, char *port, char *path)
{
    server->socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server->socket < 0)
        pterror("Socket()");
    fill_server_var(server, port, path);
    server->teams_list = init_team(server);
    if (setsockopt(server->socket, SOL_SOCKET, SO_REUSEADDR, &server->opt,
    sizeof(server->opt)))
        pterror_socket("Setsockopt().", server->socket);
    if (bind(server->socket, (struct sockaddr *)&server->addr,
        server->len) < 0)
        pterror("Bind()");
    if (listen(server->socket, max_clients) < 0)
        pterror("Listen()");
    return server;
}

void fill_server_var(server_t *server, char *port, char *path)
{
    server->port = check_port(port);
    server->addr.sin_family = AF_INET;
    server->addr.sin_port = htons(server->port);
    server->addr.sin_addr.s_addr = INADDR_ANY;
    server->len = sizeof(server->addr);
    server->path = path;
    server->is_server_active = true;
    running = &server->is_server_active;
}

client_t *init_clients(char *path)
{
    client_t *clients = calloc(sizeof(client_t), max_clients + 1);

    if (!clients)
        pterror("Clients calloc()");
    for (int i = 0; i < max_clients; i++) {
        clients[i].socket = 0;
        clients[i].wbuf = calloc(sizeof(char), 1024);
        clients[i].rbuf = calloc(sizeof(char), 1024);
        clients[i].user_name = calloc(sizeof(char), MAX_NAME_LENGTH);
        clients[i].path = path;
        clients[i].logged_in = false;
        clients[i].is_unknown_cmd = true;
        clients[i].emplacement_uuid = NULL;
        clients[i].emplacement = ROOT;
        clients[i].is_init = false;
    }
    return clients;
}

void init_str(client_t *clients, int i)
{
    memset(clients[i].wbuf, 0, 1024);
    memset(clients[i].rbuf, 0, 1024);
}
