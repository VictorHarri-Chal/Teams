/*
** EPITECH PROJECT, 2022
** myTeams
** File description:
** server
*/

#ifndef SERVER_H_
#define SERVER_H_

#include <arpa/inet.h>
#include <ctype.h>
#include <errno.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/queue.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>
#include <uuid/uuid.h>
#include "protocol.h"
#include "../../libs/myteams/logging_server.h"

#define MAX_NAME_LENGTH        32
#define MAX_DESCRIPTION_LENGTH 255
#define MAX_BODY_LENGTH        512

extern volatile bool *running;

enum emplacement { ROOT, TEAM, CHANNEL, THREAD };

typedef struct reply_t {
    char uuid[50];
    char body[MAX_BODY_LENGTH];
    time_t timestamp;
    LIST_ENTRY(reply_t) next_reply;
} reply_t;

typedef struct thread_t {
    char title[MAX_NAME_LENGTH];
    char uuid[50];
    char message[MAX_BODY_LENGTH];
    time_t timestamp;
    char creator_uuid[50];
    reply_t *replies_list;
    LIST_HEAD(, reply_t) reply_head;
    LIST_ENTRY(thread_t) next_thread;
} thread_t;

typedef struct channel_t {
    char name[MAX_NAME_LENGTH];
    char uuid[50];
    char description[MAX_DESCRIPTION_LENGTH];
    thread_t *threads_list;
    LIST_HEAD(, thread_t) thread_head;
    LIST_ENTRY(channel_t) next_channel;
} channel_t;

typedef struct subscribed_t {
    char team_uuid[50];
    char user_uuid[50];
    LIST_ENTRY(subscribed_t) next_sub;
} subscribed_t;

typedef struct team_t {
    char name[MAX_NAME_LENGTH];
    char uuid[50];
    char description[MAX_DESCRIPTION_LENGTH];
    channel_t *channels_list;
    LIST_HEAD(, channel_t) channel_head;
    subscribed_t *sub_list;
    LIST_HEAD(, subscribed_t) sub_head;
    LIST_ENTRY(team_t) next_team;
} team_t;

typedef struct server_t {
    team_t *teams_list;
    LIST_HEAD(, team_t) team_head;
    int opt;
    int client_socket[30];
    int activity;
    int socket;
    fd_set rfd;
    fd_set wfd;
    struct sockaddr_in addr;
    bool is_server_active;
    unsigned int port;
    int log_file_fd;
    int len;
    char *path;
} server_t;

typedef struct client_s {
    int socket;
    char *rbuf;
    char *wbuf;
    char *path;
    char uuid[50];
    char *emplacement_uuid;
    int emplacement;
    bool logged_in;
    bool is_unknown_cmd;
    char *user_name;
    bool is_init;
} client_t;

extern int max_clients;

//destroy.c
void destroy_sub(server_t *server);
void destroy_objects(server_t *server);
void free_objects(server_t *server);

// clients.c
void quit_client(client_t *clients, int i);
void check_commands(client_t *clients, server_t *server, int i);
void handle_clients_inputs(client_t *clients, server_t *server);

// init_user.c
void create_user(client_t *clients, int i, char username[MAX_NAME_LENGTH]);
int read_user(client_t *clients, char *uuid);

// init_team.c
team_t *init_team(server_t *server);
team_t *create_team(char name[MAX_NAME_LENGTH],
char description[MAX_DESCRIPTION_LENGTH], server_t *server);

// init_sub.c
subscribed_t *init_sub(team_t *team);
char *create_sub(char *team_uuid, char *user_uuid, team_t *team);

// read_sub.c
bool read_sub_team_and_user_uuid(char *team_uuid, char *user_uuid,
team_t *team);
bool read_sub_team_uuid(char *team_uuid, team_t *team);
bool read_sub_user_uuid(char *user_uuid, team_t *team);

// delete_sub.c
void delete_sub(char *team_uuid, char *user_uuid, team_t *team);

// team_check_name.c
bool read_team_uuid(char *uuid, server_t *server);
team_t *return_team_from_uuid(char *uuid, server_t *server);
bool read_team_name(char *name, server_t *server);

// init_channel.c
channel_t *init_channel(team_t *team);
channel_t *create_channel(char name[MAX_NAME_LENGTH],
char description[MAX_DESCRIPTION_LENGTH], team_t *team);
bool read_channel_from_team(char *uuid, server_t *server);
channel_t *return_channel_from_team(char *uuid, server_t *server);

// channel_check_name.c
bool read_channel_uuid(char *uuid, team_t *team);
channel_t *return_channel_from_uuid(char *uuid, team_t *team);
bool read_channel_name(char *name, team_t *team);

// init_thread.c
thread_t *init_thread(channel_t *channel);
thread_t *create_thread(char title[MAX_NAME_LENGTH],
char message[MAX_BODY_LENGTH], channel_t *channel, char *creator_uuid);
bool read_thread_from_team(char *uuid, server_t *server);
thread_t *return_thread_from_team(char *uuid, server_t *server);

// thread_check_name.c
bool read_thread_uuid(char *uuid, channel_t *channel);
thread_t *return_thread_from_uuid(char *uuid, channel_t *channel);
bool read_thread_name(char *name, channel_t *channel);

// init_reply.c
reply_t *init_reply(thread_t *thread);
reply_t *create_reply(char body[MAX_BODY_LENGTH], thread_t *thread);
reply_t *read_reply(char *uuid, thread_t *thread);
char *get_reply_team_uuid(char *uuid_reply, server_t *server);

// init_struct.c
server_t *init_server(server_t *server, char *port, char *path);
void fill_server_var(server_t *server, char *port, char *path);
team_t *init_team(server_t *server);
client_t *init_clients(char *path);
void init_str(client_t *clients, int i);

// args_parsing.c
int check_port(char *port);
void check_arguments(int argc, char **argv);

// server.c
void start_server(server_t *server);
void loop_server(client_t *client, server_t *server);
void add_sockets_to_set(client_t *clients, server_t *server);
void wait_for_activity_on_socket(client_t *clients, server_t *server);
void operation_on_client(server_t *server);

// core.c
void sigint_handler(int var);
void add_sockets_to_set(client_t *clients, server_t *server);
void loop_server(client_t *clients, server_t *server);
void wait_for_activity_on_socket(client_t *clients, server_t *server);
void accept_client(client_t *clients, server_t *server);

// destroy_server.c
void clean_server(client_t *clients, server_t *server);

// utils.c
void pterror(char *error);
void pterror_socket(char *error, int sock);
void usage(void);

// string_utils.c
int count_quotes(char *str);
char *remove_quotes(char *str);
bool check_quotes(char *str);

// my_str_to_tab.c
char **my_str_to_tab(char *str, char delim);

// parsing.c
void login_command_or_not(client_t *clients, server_t *server, int i);
int commands_before_logged_in(client_t *clients, server_t *server, int i);
int commands_after_logged_in(client_t *clients, server_t *server, int i);
void commands_after_logged_in_two(client_t *clients, server_t *server, int i,
char **split_cmd);
bool check_unauthorized_commands(client_t *clients, int i, char **split_cmd);

// create.c
int create(server_t *server, client_t *clients, int i, char **command);

// create_team.c
int check_create_team(server_t *server, client_t *clients, int i,
char **command);
int team_arg_parsing(client_t *clients, int i, char *team_name,
char *team_desc);
void create_team_action(client_t *clients, int i, team_t *new_team);
void team_send_event_to_client(client_t *clients, int j, int i,
team_t *new_team);

// create_channel.c
int check_create_channel(server_t *server, client_t *clients, int i,
char **command);
int channel_arg_parsing(client_t *clients, int i, char *channel_name,
char *channel_desc);
void create_channel_action(client_t *clients, int i, channel_t *new_channel,
server_t *server);
void channel_send_event_to_client(client_t *clients, int j, int i,
channel_t *new_channel);


// create_thread.c
int check_create_thread(server_t *server, client_t *clients, int i,
char **command);
int thread_arg_parsing(client_t *clients, int i, char *thread_title,
char *thread_body);
void create_thread_action(client_t *clients, int i, thread_t *new_thread,
server_t *server);
void thread_send_event_to_client(client_t *clients, int j, int i,
thread_t *new_thread);

// create_reply.c
int check_create_reply(server_t *server, client_t *clients, int i,
char **command);
void create_reply_action(client_t *clients, int i, reply_t *new_reply,
server_t *server);
void reply_send_event_to_client(client_t *clients, int j, int i,
reply_t *new_reply, server_t *server);

// help.c
int help(client_t *clients, int i, char **command);

// info.c
int info(client_t *clients, int i, char **command, server_t *server);
int check_info_user(client_t *clients, int i);
int check_info_team(client_t *clients, int i, server_t *server);
int check_info_channel(client_t *clients, int i, server_t *server);
int check_info_thread(client_t *clients, int i, server_t *server);

// list.c
int list(client_t *clients, int i, char **command);
int check_list_team(client_t *clients, int i);
int check_list_channel(client_t *clients, int i);
int check_list_thread(client_t *clients, int i);
int check_list_reply(client_t *clients, int i);

// login.c
int login(client_t *clients, int i, char **command);

// logout.c
int logout(client_t *clients, int i, char **command);

// messages.c
int messages(client_t *clients, int i, char **command);
int messages_action(client_t *clients, int i, char *user_uuid);

// send.c
int send_func(client_t *clients, int i, char **command);
int send_arg_parsing(client_t *clients, int i, char *user_uuid,
char *message_body);
int send_action(client_t *clients, int sender, char *user_uuid,
char *message_body);
void write_to_file(client_t *clients, int sender, int receiver,
char *message_body);
void write_to_file_two(client_t *clients, int sender, int receiver,
char *message_body);

// subscribe.c
int subscribe(server_t *server, client_t *clients, int i, char **command);

// subscribed?.c
int subscribed(client_t *clients, int i, char **command);

// unsubscribe.c
int unsubscribe(server_t *server, client_t *clients, int i, char **command);

// use.c
int use(server_t *server, client_t *clients, int i, char **command);
int use_without_args(client_t *clients, int i);
int check_emplacement(char *object_uuid, server_t *server,
client_t *clients, int i);

// user_check_uuid.c
void check_uuid_team(char *object_uuid, server_t *server,
client_t *clients, int i);
void check_uuid_channel(char *object_uuid, server_t *server,
client_t *clients, int i);
void check_uuid_thread(char *object_uuid, server_t *server,
client_t *clients, int i);

// user.c
int user(client_t *clients, int i, char **command);
int user_action(client_t *clients, int i, char *user_uuid);

// users.c
int users(client_t *clients, int i, char **command);
void fill_users_file(client_t *clients);

#endif /* !SERVER_H_ */
