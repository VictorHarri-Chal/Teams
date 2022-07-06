/*
** EPITECH PROJECT, 2021
** B-NWP-400-NAN-4-1-myteams-victor.harri-chal
** File description:
** string_utils.c
*/

#include "server.h"

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

bool check_quotes(char *str)
{
    if ((str[0] == '"') && (str[strlen(str) - 1] == '"'))
        return true;
    return false;
}