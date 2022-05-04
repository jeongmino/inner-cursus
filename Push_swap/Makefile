# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junoh <junoh@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/04 16:45:56 by junoh             #+#    #+#              #
#    Updated: 2022/05/04 16:48:59 by junoh            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= push_swap

SRCS 			=	srcs/push_swap.c\
					srcs/command/command_check_utils.c\
					srcs/command/command_check.c\
					srcs/command/command_push.c\
					srcs/command/command_rotate.c\
					srcs/command/command_reverse_rotate.c\
					srcs/command/command_swap.c\
					srcs/setup/setup_utils.c\
					srcs/setup/setup.c\
					srcs/sort/sort.c\
					srcs/sort/sort_five.c\
					srcs/sort/sort_four.c\
					srcs/sort/sort_three.c\
					srcs/sort/sort_util.c\
					srcs/utils/utils.c\
					srcs/utils/utils2.c\
					srcs/utils/utils3.c\

OBJS			= $(SRCS:.c=.o)

CC				= gcc
RM				= rm
CFLAGS			= -Wall -Wextra -Werror -g -fsanitize=address
RMFLAGS			= -f

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CC) ${CFLAGS} -o ${NAME} $^

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) $<

clean:
				$(RM) $(RMFLAGS) $(OBJS)

fclean:			clean
				$(RM) $(RMFLAGS) $(OBJS)

re:				fclean all

.PHONY:			all clean fclean re
