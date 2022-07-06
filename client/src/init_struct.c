    /*
** EPITECH PROJECT, 2022
** myTeams
** File description:
** init_client
*/

#include "client.h"

client_t *init_struct_client(char **av)
{
    client_t *client = malloc(sizeof(client_t));
    if (!client)
        pterror("Failed to init client.");
    client->ip = check_ip(av[1]);
    client->port = check_port(av[2]);
    return client;
}

client_t *fill_struct_client(client_t *client)
{
    client->is_client_active = true;
    client->client_socket.sin_family = AF_INET;
    client->client_socket.sin_addr.s_addr = inet_addr(client->ip);
    client->client_socket.sin_port = htons(client->port);
    client->is_client_connected = false;
    return client;
}
