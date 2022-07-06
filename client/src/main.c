/*
** EPITECH PROJECT, 2022
** myTeams
** File description:
** main
*/

#include "client.h"

int main(int ac, char **av)
{
    check_arguments(ac, av);
    client_t *client = init_struct_client(av);
    client = fill_struct_client(client);
    init_client(client);
    loop_client(client);
    return 0;
}
