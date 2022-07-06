/*
** EPITECH PROJECT, 2021
** B-NWP-400-NAN-4-1-myteams-victor.harri-chal
** File description:
** my_str_to_tab.c
*/

#include "server.h"
#include "string.h"

int my_count_word(char *src, char delim)
{
    int i = 0;
    int count = 1;
    int no_go_zone = 0;

    if (src == NULL)
        return 0;
    while (src[i] != '\n') {
        if (src[i] == '\"' && no_go_zone == 0)
            no_go_zone = 1;
        else if (src[i] == '\"' && no_go_zone == 1)
            no_go_zone = 0;
        if (src[i] == delim && no_go_zone == 0)
            count++;
        i++;
    }
    return count;
}

static int custom_strlen(char *src, char delim)
{
    int i = 0;
    int no_go_zone = 0;

    while (src[i] != '\n') {
        if (src[i] == '\"')
            no_go_zone = 1;
        if (src[i] == '\"' && (src[i + 1] == '\n' || src[i + 1] == delim))
            no_go_zone = 0;
        if (src[i] == delim && no_go_zone == 0)
            return i;
        i++;
    }
    return i;
}

char **my_str_to_tab(char *str, char delim)
{
    int i = 0;
    int j = 0;
    int len = 0;
    char **tab;
    int nb = my_count_word(str, delim);

    if (nb < 0 || !(tab = malloc(sizeof(char *) * (nb + 1))))
        return NULL;
    for (i = 0; i < nb; i++) {
        len = custom_strlen(str, delim);
        if (!(tab[i] = malloc(sizeof(char) * (len + 2))))
            return NULL;
        for (j = 0; j < len; j++ , str++)
            tab[i][j] = *str;
        str++;
        tab[i][j] = '\0';
    }
    tab[i] = NULL;
    return tab;
}
