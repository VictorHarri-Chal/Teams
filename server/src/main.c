/*
** EPITECH PROJECT, 2022
** myTeams
** File description:
** main
*/

#include "server.h"

int main(int ac, char **av)
{
    server_t *server;
    client_t *clients;

    check_arguments(ac, av);
    max_clients = 30;
    if (!(server = malloc(sizeof(server_t))))
        pterror("Malloc()");
    server->opt = 1;
    server = init_server(server, av[1], av[2]);
    clients = init_clients(av[2]);
    signal(SIGINT, sigint_handler);
    loop_server(clients, server);
    destroy_objects(server);
    free_objects(server);
    return 0;
}
