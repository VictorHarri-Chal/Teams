/*
** EPITECH PROJECT, 2021
** B-NWP-400-NAN-4-1-myteams-victor.harri-chal
** File description:
** parsing.c
*/

#include "server.h"

void login_command_or_not(client_t *clients, server_t *server, int i)
{
    if (!clients[i].logged_in)
        commands_before_logged_in(clients, server, i);
    else if (clients[i].logged_in)
        commands_after_logged_in(clients, server, i);
}

int commands_before_logged_in(client_t *clients, server_t *server, int i)
{
    (void)server;
    char **split_cmd = my_str_to_tab(clients[i].rbuf, ' ');

    if (strncmp(split_cmd[0], "/login", 7) == 0) {
        login(clients, i, split_cmd);
        return 1;
    }
    if (strncmp(split_cmd[0], "/help", 6) == 0) {
        help(clients, i, split_cmd);
        return 1;
    }
    if (check_unauthorized_commands(clients, i, split_cmd))
        return 1;
    dprintf(clients[i].socket, "%s", UNKOWN_COMMAND);
    return 0;
}

int commands_after_logged_in(client_t *clients, server_t *server, int i)
{
    clients[i].is_unknown_cmd = true;
    char **split_cmd = my_str_to_tab(clients[i].rbuf, ' ');

    if (strncmp(split_cmd[0], "/help", 6) == 0)
        help(clients, i, split_cmd);
    if (strncmp(split_cmd[0], "/logout", 8) == 0)
        logout(clients, i, split_cmd);
    if (strncmp(split_cmd[0], "/users", 7) == 0)
        users(clients, i, split_cmd);
    if (strncmp(split_cmd[0], "/user", 6) == 0)
        user(clients, i, split_cmd);
    if (strncmp(split_cmd[0], "/send", 6) == 0)
        send_func(clients, i, split_cmd);
    if (strncmp(split_cmd[0], "/messages", 10) == 0)
        messages(clients, i, split_cmd);
    commands_after_logged_in_two(clients, server, i, split_cmd);
    if (clients[i].is_unknown_cmd == false)
        return 1;
    dprintf(clients[i].socket, "%s", UNKOWN_COMMAND);
    return 0;
}

void commands_after_logged_in_two(client_t *clients, server_t *server, int i,
char **split_cmd)
{
    if (strncmp(split_cmd[0], "/subscribe", 11) == 0)
        subscribe(server, clients, i, split_cmd);
    if (strncmp(split_cmd[0], "/subscribed", 12) == 0)
        subscribed(clients, i, split_cmd);
    if (strncmp(split_cmd[0], "/unsubscribe", 13) == 0)
        unsubscribe(server, clients, i, split_cmd);
    if (strncmp(split_cmd[0], "/use", 5) == 0)
        use(server, clients, i, split_cmd);
    if (strncmp(split_cmd[0], "/create", 8) == 0)
        create(server, clients, i, split_cmd);
    if (strncmp(split_cmd[0], "/list", 6) == 0)
        list(clients, i, split_cmd);
    if (strncmp(split_cmd[0], "/info", 6) == 0)
        info(clients, i, split_cmd, server);
}

bool check_unauthorized_commands(client_t *clients, int i, char **split_cmd)
{
    if ((strncmp(split_cmd[0], "/logout", 8) == 0) ||
    (strncmp(split_cmd[0], "/users", 7) == 0) ||
    (strncmp(split_cmd[0], "/user", 6) == 0) ||
    (strncmp(split_cmd[0], "/send", 6) == 0) ||
    (strncmp(split_cmd[0], "/messages", 10) == 0) ||
    (strncmp(split_cmd[0], "/subscribe", 11) == 0) ||
    (strncmp(split_cmd[0], "/subscribed", 12) == 0) ||
    (strncmp(split_cmd[0], "/unsubscribe", 13) == 0) ||
    (strncmp(split_cmd[0], "/use", 5) == 0) ||
    (strncmp(split_cmd[0], "/create", 8) == 0) ||
    (strncmp(split_cmd[0], "/list", 6) == 0) ||
    (strncmp(split_cmd[0], "/info", 6) == 0)) {
        dprintf(clients[i].socket, "%s", PERMISSION_DENIED);
        return true;
    }
    return false;
}
