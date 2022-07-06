/*
** EPITECH PROJECT, 2022
** myTeams
** File description:
** client
*/

#ifndef CLIENT_H_
    #define CLIENT_H_

    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <stdbool.h>
    #include <stddef.h>
    #include <string.h>
    #include <fcntl.h>
    #include <ctype.h>
    #include <sys/types.h>
    #include <sys/socket.h>
    #include <sys/select.h>
    #include <sys/time.h>
    #include <sys/stat.h>
    #include <arpa/inet.h>
    #include <netinet/in.h>
    #include "../../libs/myteams/logging_client.h"

    typedef struct client_s {
        int client_fd;
        int server_fd;
        struct sockaddr_in client_socket;
        socklen_t client_size;
        bool is_client_connected;
        fd_set readfs;
        fd_set tmpfs;
        bool is_client_active;
        char *ip;
        unsigned int port;
    } client_t;

    // check_protocol.c
    void check_protocol(char *input);
    void check_events(char **split_cmd);
    void check_events_two(char **split_cmd);

    // check_protocol_intern_commands.c
    void check_intern_commands(char **split_cmd);
    void check_intern_commands_two(char **split_cmd);
    void check_intern_commands_three(char **split_cmd);
    void check_intern_commands_four(char **split_cmd);
    void check_intern_commands_five(char **split_cmd);

    // check_protocol_errors.c
    void check_errors(char **split_cmd);
    void check_syntax_errors(char **split_cmd);

    // core.c
    void init_client(client_t *client);
    void loop_client(client_t *client);
    void accept_client(client_t *client, int i);

    // help.c
    void help_command(void);
    void help_command_two(void);

    // init_struct.c
    client_t *init_struct_client(char **argv);
    client_t *fill_struct_client(client_t *client);

    // parsing.c
    char *check_ip(char *ip);
    int check_port(char *port);
    void check_arguments(int argc, char **argv);
    bool check_protocole(char *input);

    // my_str_to_tab.c
    char **my_str_to_tab(char *str, char delim);

    // utils.c
    void pterror(char *error);
    void pterror_socket(char *error, int sock);
    void print_usage(void);
    int count_quotes(char *str);
    char *remove_quotes(char *str);

    // messages.c
    void messages_options_one(char *options1, char *options2);
    int messages_options_two(char *options2);

    // users.c
    void users_command(void);

#endif /* !CLIENT_H_ */
