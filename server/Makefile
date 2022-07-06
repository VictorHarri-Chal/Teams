##
## EPITECH PROJECT, 2022
## myTeams
## File description:
## Makefile
##

SRC             =       src/core.c                                  \
						src/clients.c 								\
						src/global.c 								\
						src/destroy.c 								\
						src/init_struct.c 							\
						src/main.c 									\
						src/user.c 									\
						src/team_utils/init_team.c 					\
						src/team_utils/read_team.c 					\
						src/sub_utils/init_sub.c 					\
						src/sub_utils/read_sub.c 					\
						src/sub_utils/delete_sub.c 					\
						src/channel_utils/init_channel.c 			\
						src/channel_utils/read_channel.c 			\
						src/thread_utils/init_thread.c 				\
						src/thread_utils/read_thread.c 				\
						src/reply.c 								\
						src/string_utils.c 							\
						src/utils.c 								\
						src/my_str_to_tab.c 						\
						src/parsing.c 								\
						src/args_parsing.c 							\
						src/destroy_server.c 						\
						src/features/login.c 						\
						src/features/logout.c 						\
						src/features/help.c 						\
						src/features/users.c 						\
						src/features/user.c 						\
						src/features/send.c 						\
						src/features/messages.c 					\
						src/features/subscribe.c 					\
						src/features/subscribed.c 					\
						src/features/unsubscribe.c 					\
						src/features/use.c 							\
						src/features/use_check_uuid.c 				\
						src/features/create.c 						\
						src/features/create_team.c 					\
						src/features/create_channel.c 				\
						src/features/create_thread.c 				\
						src/features/create_reply.c 				\
						src/features/list.c 						\
						src/features/info.c 						\

NAME    =       myteams_server

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
								mv $(NAME) $(ROOT)
								$(RM) $(OBJ)

clean:
								rm -f $(OBJ)

re:                     clean all

.PHONY: all     clean   fclean  re
