/*
** EPITECH PROJECT, 2022
** myTeams
** File description:
** parsing
*/

#include "client.h"
#include <string.h>

char *check_ip(char *ip)
{
    if (strlen(ip) != 9)
        pterror("The ip length must be correct.");
    for (int i = 0; i != 3; i++) {
        if (isdigit(ip[i]) == 0)
            pterror("The ip must be correct.");
    }
    if (ip[3] != '.' || isdigit(ip[4]) == 0 || ip[5] != '.' ||
    isdigit(ip[6]) == 0 || ip[7] != '.' || isdigit(ip[8]) == 0)
        pterror("The ip must be correct.");
    return ip;
}

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
    if (argc == 2 && (strcmp("-help", argv[1]) == 0))
        print_usage();
    if (argc != 3)
        pterror("Wrong number of arguments.");
}
