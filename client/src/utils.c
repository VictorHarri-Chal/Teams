/*
** EPITECH PROJECT, 2022
** myTeams
** File description:
** utils
*/

#include "client.h"

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

void print_usage(void)
{
    printf("USAGE: ./myteams_cli ip port\n");
    printf("\tip is the server ip address on which the server ");
    printf("socket listens\n");
    printf("\tport is the port number on which the server ");
    printf("socket listens\n");
    exit(0);
}

int count_quotes(char *str)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '"')
            count++;
    }
    return count;
}

char *remove_quotes(char *str)
{
    int j = 0;
    int k = 0;

    int nb_quotes = count_quotes(str);
    char *tmp = malloc(sizeof(char) * ((strlen(str) - nb_quotes) + 1));
    while (true) {
        while (str[k] == '"')
            k++;
        tmp[j] = str[k];
        j++;
        k++;
        while (str[k] == '"')
            k++;
        if (str[k] == '\0') {
            tmp[j] = '\0';
            return tmp;
        }
    }
    return tmp;
}
