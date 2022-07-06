/*
** EPITECH PROJECT, 2021
** B-NWP-400-NAN-4-1-myteams-victor.harri-chal
** File description:
** users.c
*/

#include "client.h"

void users_command(void)
{
    FILE *fp;

    fp = fopen("users/users.txt", "r");
    while (true) {
        char str[1024] = "";
        fgets(str, 1024, fp);
        if (strcmp(str, "") == 0)
            break;
        char **tab = my_str_to_tab(str, ' ');
        client_print_users(remove_quotes(tab[0]), remove_quotes(tab[1]),
            atoi(remove_quotes(tab[2])));
    }
    fclose(fp);
}
