/*
** EPITECH PROJECT, 2021
** B-NWP-400-NAN-4-1-myteams-victor.harri-chal
** File description:
** check_protocol_intern_commands.c
*/

#include "client.h"

void check_intern_commands(char **split_cmd)
{
    if (strncmp(split_cmd[0], "220", 4) == 0)
        users_command();
    if (strncmp(split_cmd[0], "221", 4) == 0) {
        client_print_teams(split_cmd[1], remove_quotes(split_cmd[2]),
            remove_quotes(split_cmd[3]));
    }
    if (strncmp(split_cmd[0], "222", 4) == 0) {
        client_team_print_channels(split_cmd[1], remove_quotes(split_cmd[2]),
            remove_quotes(split_cmd[3]));
    }
    if (strncmp(split_cmd[0], "223", 4) == 0) {
        client_channel_print_threads(split_cmd[1], split_cmd[2],
        (time_t)split_cmd[3], remove_quotes(split_cmd[4]),
        remove_quotes(split_cmd[5]));
    }
    if (strncmp(split_cmd[0], "224", 4) == 0) {
        client_thread_print_replies(split_cmd[1], split_cmd[2],
        (time_t)split_cmd[3], remove_quotes(split_cmd[4]));
    }
    check_intern_commands_two(split_cmd);
}

void check_intern_commands_two(char **split_cmd)
{
    if (strncmp(split_cmd[0], "230", 4) == 0) {
        client_print_user(split_cmd[1], remove_quotes(split_cmd[2]),
            atoi(split_cmd[3]));
    }
    if (strncmp(split_cmd[0], "231", 4) == 0) {
        client_print_team(split_cmd[1], remove_quotes(split_cmd[2]),
            remove_quotes(split_cmd[3]));
    }
    if (strncmp(split_cmd[0], "241", 4) == 0) {
        if (split_cmd[4] != NULL) {
            client_print_channel_created(split_cmd[1],
                remove_quotes(split_cmd[2]), remove_quotes(split_cmd[3]));
            client_event_channel_created(split_cmd[1],
                remove_quotes(split_cmd[2]), remove_quotes(split_cmd[3]));
            return;
        }
        client_print_channel_created(split_cmd[1], remove_quotes(split_cmd[2]),
            remove_quotes(split_cmd[3]));
    }
    check_intern_commands_three(split_cmd);
}

void check_intern_commands_three(char **split_cmd)
{
    if (strncmp(split_cmd[0], "232", 4) == 0) {
        client_print_channel(split_cmd[1], remove_quotes(split_cmd[2]),
            remove_quotes(split_cmd[3]));
    }
    if (strncmp(split_cmd[0], "233", 4) == 0) {
        client_print_thread(split_cmd[1], split_cmd[2], (time_t)split_cmd[3],
            remove_quotes(split_cmd[4]), remove_quotes(split_cmd[5]));
    }
    if (strncmp(split_cmd[0], "240", 4) == 0) {
        if (split_cmd[4] != NULL) {
            client_print_team_created(split_cmd[1], remove_quotes(split_cmd[2]),
                remove_quotes(split_cmd[3]));
            client_event_team_created(split_cmd[1], remove_quotes(split_cmd[2]),
                remove_quotes(split_cmd[3]));
            return;
        }
        client_print_team_created(split_cmd[1], remove_quotes(split_cmd[2]),
            remove_quotes(split_cmd[3]));
    }
    check_intern_commands_four(split_cmd);
}

void check_intern_commands_four(char **split_cmd)
{
    if (strncmp(split_cmd[0], "243", 4) == 0) {
        if (split_cmd[5] != NULL) {
            client_print_reply_created(split_cmd[1], split_cmd[2],
                (time_t)split_cmd[3], remove_quotes(split_cmd[4]));
            client_event_thread_reply_received(split_cmd[6],
                split_cmd[1], split_cmd[2], remove_quotes(split_cmd[4]));
            return;
        }
        client_print_reply_created(split_cmd[1], split_cmd[2],
            (time_t)split_cmd[3], remove_quotes(split_cmd[4]));
    }
    if (strncmp(split_cmd[0], "225", 4) == 0)
        messages_options_one(split_cmd[1], split_cmd[2]);
    if (strncmp(split_cmd[0], "250", 4) == 0)
        client_print_subscribed(split_cmd[1], split_cmd[2]);
    if (strncmp(split_cmd[0], "251", 4) == 0)
        client_print_unsubscribed(split_cmd[1], split_cmd[2]);
    check_intern_commands_five(split_cmd);
}

void check_intern_commands_five(char **split_cmd)
{
    if (strncmp(split_cmd[0], "242", 4) == 0) {
        if (split_cmd[6] != NULL) {
            client_print_thread_created(split_cmd[1], split_cmd[2],
                (time_t)split_cmd[3], remove_quotes(split_cmd[4]),
                remove_quotes(split_cmd[5]));
            client_event_thread_created(split_cmd[1], split_cmd[2],
                (time_t)split_cmd[3], remove_quotes(split_cmd[4]),
                remove_quotes(split_cmd[5]));
            return;
        }
        client_print_thread_created(split_cmd[1], split_cmd[2],
        (time_t)split_cmd[3], remove_quotes(split_cmd[4]),
        remove_quotes(split_cmd[5]));
    }
}