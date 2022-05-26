# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junoh <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/26 13:16:22 by junoh             #+#    #+#              #
#    Updated: 2022/05/26 13:17:20 by junoh            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= pipex

SRCS 			=	src/pipex.c\
					src/pipex_util.c\
					src/pipex_split.c\

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
