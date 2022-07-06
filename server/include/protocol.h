/*
** EPITECH PROJECT, 2021
** B-NWP-400-NAN-4-1-myteams-victor.harri-chal
** File description:
** protocol.h
*/

#ifndef _PROTOCOL_H_
    #define _PROTOCOL_H_

    // GLOBAL COMMAND //

    // 100 Default call command okay.
    #define CMD_OK "100"
    // 110 Help command
    #define HELP_CMD "110"
    // 999 Kill client
    #define KILL_CLIENT "999"

    // EXTERN EVENT //

    // 200 Event connected to existing user.
    #define EVENT_EXISTING_USER_LOGGED_IN "200"
    // 201 Event connected to new user.
    #define EVENT_NEW_USER_LOGGED_IN "201"
    // 202 Event user disconnected.
    #define EVENT_DISCONNECTED_USER "202"
    // 203 Event private message received
    #define EVENT_PRIVATE_MSG_RCV "203"
    // 204 Event thread reply received
    #define EVENT_THREAD_REPLY_RCV "204"

    // 205 Event team created
    #define EVENT_TEAM_CREATED "205"
    // 206 Event channel create
    #define EVENT_CHANNEL_CREATED "206"
    // 207 Event thread created
    #define EVENT_THREAD_CREATED "207"

    // INTERN COMMAND CALL //

    // 220 Print users
    #define PRINT_USERS "220"
    // 221 Print teams
    #define PRINT_TEAMS "221"
    // 222 Print channels
    #define PRINT_CHANNELS "222"
    // 223 Print_threads
    #define PRINT_THREADS "223"
    // 224 Print replies
    #define PRINT_REPLIES "224"
    // 225 Print privates messages
    #define PRINT_PRIVATE_MSGS "225"

    // 230 Print_info_user
    #define PRINT_INFO_USER "230"
    // 231 Print_info_team
    #define PRINT_INFO_TEAM "231"
    // 232 Print_info_channel
    #define PRINT_INFO_CHANNEL "232"
    // 233 Print_info_thread
    #define PRINT_INFO_THREAD "233"

    // 240 Print team created
    #define PRINT_TEAM_CREATED "240"
    // 241 Print channel create
    #define PRINT_CHANNEL_CREATED "241"
    // 242 Print thread created
    #define PRINT_THREAD_CREATED "242"
    // 243 Print reply created
    #define PRINT_REPLY_CREATED "243"

    // 250 Print user subscribed
    #define PRINT_USER_SUBSCRIBED "250"
    // 251 Print user unsubscribed
    #define PRINT_USER_UNSUBSCRIBED "251"

    // ERRORS //

    // 500 Unknown command
    #define UNKOWN_COMMAND "500"
    // 510 Requested UUID not found
    #define UUID_NOT_FOUND "510"
    // 511 Requested TEAM_UUID not found
    #define TEAM_UUID_NOT_FOUND "511"
    // 512 Requested CHANNEL_UUID not found
    #define CHANNEL_UUID_NOT_FOUND "512"
    // 513 Requested THREAD_UUID not found
    #define THREAD_UUID_NOT_FOUND "513"
    // 520 Permission denied (create a team he is not sub,
    // create a team when not logged id, etc...)
    #define PERMISSION_DENIED "520"
    // 530 This object already exist (team, channel, thread)
    #define ALREADY_EXIST "530"

    // SYNTAX ERRORS //

    // 800 Name too long
    #define NAME_TOO_LONG "800"
    // 810 Description too long
    #define DESC_TOO_LONG "810"
    // 820 Body too long
    #define BODY_TOO_LONG "820"
    // 830 Invalid format (wrong number of argument etc...)
    #define INVALID_FORMAT "830"

#endif
