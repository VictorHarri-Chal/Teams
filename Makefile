##
## EPITECH PROJECT, 2022
## myTeams
## File description:
## Makefile
##

all:            server client

server:
								make -C server/

client:
								make -C client/
clean:
								make clean -C server/
								make clean -C client/

fclean: clean
								rm -rf myteams_server
								rm -rf myteams_cli

re:                     fclean all

.PHONY: all     clean   fclean  re server client
