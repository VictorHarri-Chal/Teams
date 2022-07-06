##
## EPITECH PROJECT, 2022
## myTeams
## File description:
## Makefile
##

SRC             =       src/core.c                                  \
						src/init_struct.c                           \
						src/main.c                                  \
						src/parsing.c 								\
						src/utils.c 								\
						src/check_protocol.c 						\
						src/check_protocol_errors.c 				\
						src/check_protocol_intern_commands.c 		\
						src/my_str_to_tab.c 						\
						src/features/help.c 						\
						src/features/messages.c 					\
						src/features/users.c 						\

NAME    =       myteams_cli

OBJ     =               $(SRC:.c=.o)

CC      =       gcc

CFLAGS += -Wall -Wextra -Wpedantic -I./include/ -I./libs/myteams/

LDFLAGS += -L../libs/myteams/ -luuid -lmyteams

ROOT= ../

%.o : %.c
	$(CC) -o $@ $(CFLAGS) -c $<

all:            $(NAME)

$(NAME):                $(OBJ)
								$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS)
								$(RM) $(OBJ)
								mv $(NAME) $(ROOT)

clean:
								rm -f $(OBJ)

re:                     clean all

.PHONY: all     clean   re
