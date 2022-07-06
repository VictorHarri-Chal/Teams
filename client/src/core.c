/*
** EPITECH PROJECT, 2022
** myTeams
** File description:
** core
*/

#include "client.h"
#include <stdio.h>
#include <stdlib.h>

int send_to_server(client_t *client)
{
    size_t size = 1024;
    char *buffer = malloc(size);

    int i = getline(&buffer, &size, stdin);
    if (i <= 0 || !*buffer)
        pterror("getline client error");
    write(client->server_fd, buffer, 1024);
    return 0;
}

int read_from_server(client_t *client)
{
    char input[1024];

    memset(input, 0, 1024);
    read(client->client_fd, input, 1024);
    check_protocol(input);
    memset(input, 0, 1024);
    return (0);
}

void init_client(client_t *client)
{
    client->client_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (client->client_fd  == 0)
        pterror("Socket init failed.");
    if (connect(client->client_fd, (struct sockaddr *)&client->client_socket,
    sizeof(client->client_socket)) != 0)
        pterror("Connect to server failed");
}

void loop_client(client_t *client)
{
    client->server_fd = client->client_fd;
    FD_ZERO(&client->tmpfs);
    FD_ZERO(&client->readfs);
    FD_SET(STDIN_FILENO, &client->tmpfs);
    FD_SET(client->client_fd, &client->tmpfs);
    client->client_size = sizeof(client->client_socket);
    while (client->is_client_active) {
        client->readfs = client->tmpfs;
        if (select(FD_SETSIZE, &client->readfs,
            NULL, NULL, NULL) < 0)
            pterror_socket("Select failed.", client->client_fd);
        if (FD_ISSET(STDIN_FILENO, &client->readfs))
            send_to_server(client);
        else if (FD_ISSET(client->client_fd, &client->readfs))
            read_from_server(client);
    }
    close(client->client_fd);
    free(client);
}
