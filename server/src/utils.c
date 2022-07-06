/*
** EPITECH PROJECT, 2022
** myTeams
** File description:
** utils
*/

#include "server.h"

void pterror(char *error)
{
    fprintf(stdout, "%s\n", error);
    exit(84);
}

void pterror_socket(char *error, int sock)
{
    fprintf(stdout, "%s\n", error);
    close(sock);
    exit(84);
}

void usage(void)
{
    printf("USAGE: ./myteams_server port\n");
    printf("\tport  is the port number on which the server socket listens\n");
    exit(0);
}
