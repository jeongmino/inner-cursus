# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junoh <junoh@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/27 12:05:03 by junoh             #+#    #+#              #
#    Updated: 2022/09/27 15:19:21 by junoh            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
NAME = philo
# CFLAGS = -Wall -Werror -Wextra
# CFLAGS = -Wall -Werror -Wextra -fsanitize=thread -g
CFLAGS = -Wall -Werror -Wextra -fsanitize=address

SRCS = philo.c			\
	   create_philo.c	\
	   init_info.c		\
	   parse_arg.c		\
	   routine.c		\
	   print.c			\
	   timer.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -lpthread -o $@

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

lldb: $(NAME)
	$(CC) $(CFLAGS) $(SRCS) -g -lpthread -o $(NAME)

re:
	make fclean
	make all

.PHONY: all clean fclean re
