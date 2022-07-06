/*
** EPITECH PROJECT, 2021
** B-NWP-400-NAN-4-1-myteams-victor.harri-chal
** File description:
** args_parsing.c
*/

#include "server.h"

int check_port(char *port)
{
    for (int i = 0; port[i] != '\0'; i++) {
        if (isdigit(port[i]) == 0)
            pterror("The port must be an unsigned integer.");
    }
    return atoi(port);
}

void check_arguments(int argc, char **argv)
{
    if (argc == 2 && (strcmp("-h", argv[1]) == 0))
        usage();
    if (argc != 2)
        pterror("Wrong number of arguments.");
}
