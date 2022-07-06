/*
** EPITECH PROJECT, 2021
** B-NWP-400-NAN-4-1-myteams-victor.harri-chal
** File description:
** send.c
*/

#include "server.h"

int send_func(client_t *clients, int i, char **command)
{
    clients[i].is_unknown_cmd = false;
    if (command[3] != NULL || command[1] == NULL || command[2] == NULL) {
        dprintf(clients[i].socket, "%s", INVALID_FORMAT);
        return 1;
    }
    if (!check_quotes(command[1]) || !check_quotes(command[2])) {
        dprintf(clients[i].socket, "%s", INVALID_FORMAT);
        return 1;
    }
    char *user_uuid = remove_quotes(command[1]);
    char *message_body = remove_quotes(command[2]);
    if (send_arg_parsing(clients, i, user_uuid, message_body) == 1)
        return 1;
    send_action(clients, i, user_uuid, message_body);
    return 0;
}

int send_arg_parsing(client_t *clients, int i, char *user_uuid,
char *message_body)
{
    if (strcmp(clients[i].uuid, user_uuid) == 0) {
        dprintf(clients[i].socket, "%s %s", UUID_NOT_FOUND, user_uuid);
        return 1;
    }
    if (strlen(message_body) > MAX_BODY_LENGTH) {
        dprintf(clients[i].socket, "%s", BODY_TOO_LONG);
        return 1;
    }
    else if (strlen(message_body) == 0) {
        dprintf(clients[i].socket, "%s", INVALID_FORMAT);
        return 1;
    }
    return 0;
}

int send_action(client_t *clients, int sender, char *user_uuid,
char *message_body)
{
    int receiver = read_user(clients, user_uuid);
    if (receiver == 31) {
        dprintf(clients[sender].socket, "%s %s", UUID_NOT_FOUND, user_uuid);
        return 1;
    } else {
        dprintf(clients[receiver].socket, "%s \"%s\" \"%s\" %s",
            EVENT_PRIVATE_MSG_RCV, clients[sender].user_name, message_body,
            user_uuid);
        server_event_private_message_sended(clients[sender].uuid, user_uuid,
            message_body);
        write_to_file(clients, sender, receiver, message_body);
        dprintf(clients[sender].socket, "%s", CMD_OK);
    }
    return 0;
}

void write_to_file(client_t *clients, int sender, int receiver,
char *message_body)
{
    FILE *fp;
    FILE *fp2;
    char filename1[25];

    time_t timestamp = time(NULL);
    sprintf(filename1, "discussions/%d-%d.txt", receiver, sender);
    if ((fp = fopen(filename1, "r"))) {
        fclose(fp);
        fp2 = fopen(filename1, "a+");
        fprintf(fp2, "\"%s\" \"%ld\" \"%s\"\n", clients[sender].uuid,
            timestamp, message_body);
        fclose(fp2);
    } else {
        write_to_file_two(clients, sender, receiver, message_body);
    }
}

void write_to_file_two(client_t *clients, int sender, int receiver,
char *message_body)
{
    FILE *fp;
    char filename2[25];

    time_t timestamp = time(NULL);
    sprintf(filename2, "discussions/%d-%d.txt", sender, receiver);
    fp = fopen(filename2, "a+");
    fprintf(fp, "\"%s\" \"%ld\" \"%s\"\n", clients[sender].uuid,
        timestamp, message_body);
    fclose(fp);
}
