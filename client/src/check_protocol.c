/*
** EPITECH PROJECT, 2021
** B-NWP-400-NAN-4-1-myteams-victor.harri-chal
** File description:
** check_protocol.c
*/

#include "client.h"

void check_protocol(char *input)
{
    char **split_cmd = my_str_to_tab(input, ' ');

    if (strncmp(split_cmd[0], "100", 4) == 0)
        printf("100 Command ok\n");
    if (strncmp(split_cmd[0], "110", 4) == 0)
        help_command();
    if (strncmp(split_cmd[0], "999", 4) == 0) {
        printf("Lost connection with the server\n");
        exit(0);
    }
    check_events(split_cmd);
    check_intern_commands(split_cmd);
    check_errors(split_cmd);
    check_syntax_errors(split_cmd);
}

void check_events(char **split_cmd)
{
    if (strncmp(split_cmd[0], "200", 4) == 0)
        client_event_logged_in(split_cmd[1], remove_quotes(split_cmd[2]));
    if (strncmp(split_cmd[0], "201", 4) == 0)
        client_event_logged_in(split_cmd[1], remove_quotes(split_cmd[2]));
    if (strncmp(split_cmd[0], "202", 4) == 0) {
        if (split_cmd[3] != NULL) {
            client_event_logged_out(split_cmd[1], remove_quotes(split_cmd[2]));
            printf("Lost connection with the server\n");
            exit(0);
        }
        client_event_logged_out(split_cmd[1], remove_quotes(split_cmd[2]));
    }
    if (strncmp(split_cmd[0], "203", 4) == 0) {
        client_event_private_message_received(split_cmd[3],
            remove_quotes(split_cmd[2]));
    }
    check_events_two(split_cmd);
}

void check_events_two(char **split_cmd)
{
    if (strncmp(split_cmd[0], "204", 4) == 0) {
        client_event_thread_reply_received(split_cmd[1],
            split_cmd[2], split_cmd[3], remove_quotes(split_cmd[4]));
    }
    if (strncmp(split_cmd[0], "205", 4) == 0) {
        client_event_team_created(split_cmd[1], remove_quotes(split_cmd[2]),
            remove_quotes(split_cmd[3]));
    }
    if (strncmp(split_cmd[0], "206", 4) == 0) {
        client_event_channel_created(split_cmd[1], remove_quotes(split_cmd[2]),
            remove_quotes(split_cmd[3]));
    }
    if (strncmp(split_cmd[0], "207", 4) == 0) {
        client_event_thread_created(split_cmd[1], split_cmd[2],
            (time_t)split_cmd[3], remove_quotes(split_cmd[4]),
            remove_quotes(split_cmd[5]));
    }
}
