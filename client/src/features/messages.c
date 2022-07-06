/*
** EPITECH PROJECT, 2021
** B-NWP-400-NAN-4-1-myteams-victor.harri-chal
** File description:
** messages.c
*/

#include "client.h"

void messages_options_one(char *options1, char *options2)
{
    FILE *fp;

    if ((fp = fopen(options1, "r")) != NULL) {
        while (true) {
            char str[1024] = "";
            fgets(str, 1024, fp);
            if (strcmp(str, "") == 0)
                break;
            char **tab = my_str_to_tab(str, ' ');
            client_private_message_print_messages(remove_quotes(tab[0]),
            (time_t)remove_quotes(tab[1]), remove_quotes(tab[2]));
            free(tab);
        }
        fclose(fp);
        return;
    }
    if (messages_options_two(options2) == 1)
        return;
    printf("No messages to print\n");
}

int messages_options_two(char *options2)
{
    FILE *fp;

    if ((fp = fopen(options2, "r")) != NULL) {
        while (true) {
            char str[1024] = "";
            fgets(str, 1024, fp);
            if (strcmp(str, "") == 0)
                break;
            char **tab = my_str_to_tab(str, ' ');
            client_private_message_print_messages(remove_quotes(tab[0]),
            (time_t)remove_quotes(tab[1]), remove_quotes(tab[2]));
            free(tab);
        }
        fclose(fp);
        return 1;
    }
    return 0;
}
