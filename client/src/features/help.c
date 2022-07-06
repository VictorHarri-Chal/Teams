/*
** EPITECH PROJECT, 2021
** B-NWP-400-NAN-4-1-myteams-victor.harri-chal
** File description:
** help.c
*/

#include "client.h"

void help_command(void)
{
    printf("HELP\n");
    printf("\tYou need to login in order to use teams\n");
    printf("\t/login [\"user_name\"] | log yourself to teams\n");
    printf("\tTeams commands :\n");
    printf("\t/logout | disconnect yourself from the server\n");
    printf("\t/users | display the list of all user using teams currently\n");
    printf("\t/user [\"user_uuid\"] | display information about a user\n");
    printf("\t/send [\"user_uuid\"] [\"message_body\"] | ");
    printf("send a message to a user\n");
    printf("\t/messages [\"user_uuid\"] | ");
    printf("display the list of all exchanges with an user\n");
    printf("\t/subscribe [\"team_uuid\"] | subscribe to the event of a team ");
    printf("and its sub directories\n");
    printf("\t/subscribed [\"user_uuid\"] or [\"team_uuid\"] | list all");
    printf(" subscribed teams or list all users subscribes to a team\n");
    printf("\t/unsubscribe [\"team_uuid\"] | unscubscribe to a team\n");
    printf("\t/use [\"team_uuid\"] | [\"channel_uuid\"] | [\"thread_uuid\"]");
    printf(" | use specify context team/channel/thread\n");
    help_command_two();
}

void help_command_two(void)
{
    printf("\t/create [\"team_name\"] [\"team_description\"] | ");
    printf("create a new team, you can do it only at root\n");
    printf("\t/create [\"channel_name\"] [\"channel_description\"] | ");
    printf(" create a new channel, you can do it only in a team\n");
    printf("\t/create [\"thread_title\"] [\"thread_message\"] | ");
    printf("create a new thread, you can do it only in a channel\n");
    printf("\t/create [\"comment_body\"] | create a new reply, ");
    printf("you can do it only in a thread\n");
    printf("\t/list | ");
    printf("depending on the context : root, team, channel or thread\n");
    printf("\t/info | ");
    printf("depending on the context : root, team, channel or thread\n");
}
