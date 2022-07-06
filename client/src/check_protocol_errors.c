/*
** EPITECH PROJECT, 2021
** B-NWP-400-NAN-4-1-myteams-victor.harri-chal
** File description:
** check_protocol_errors.c
*/

#include "client.h"

void check_errors(char **split_cmd)
{
    if (strncmp(split_cmd[0], "500", 4) == 0)
        printf("500 Unknown command\n");
    if (strncmp(split_cmd[0], "510", 4) == 0)
        client_error_unknown_user(split_cmd[1]);
    if (strncmp(split_cmd[0], "511", 4) == 0)
        client_error_unknown_team(split_cmd[1]);
    if (strncmp(split_cmd[0], "512", 4) == 0)
        client_error_unknown_channel(split_cmd[1]);
    if (strncmp(split_cmd[0], "513", 4) == 0)
        client_error_unknown_thread(split_cmd[1]);
    if (strncmp(split_cmd[0], "520", 4) == 0)
        client_error_unauthorized();
    if (strncmp(split_cmd[0], "530", 4) == 0)
        client_error_already_exist();
}

void check_syntax_errors(char **split_cmd)
{
    if (strncmp(split_cmd[0], "800", 4) == 0)
        printf("800 Name too long\n");
    if (strncmp(split_cmd[0], "810", 4) == 0)
        printf("810 Description too long\n");
    if (strncmp(split_cmd[0], "820", 4) == 0)
        printf("820 Body too long\n");
    if (strncmp(split_cmd[0], "830", 4) == 0)
        printf("830 Invalid format\n");
}
