# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junoh <junoh@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/26 13:16:22 by junoh             #+#    #+#              #
#    Updated: 2022/06/07 17:21:30 by junoh            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= pipex

SRCS 			=	src/pipex_bonus.c\
					src/pipex_child_proc.c\
					src/pipex_exec.c\
					src/pipex_make_pipe.c\
					src/pipex_parent_proc.c\
					src/pipex_parent_proc.c\
					src/pipex_openfile.c\
					src/pipex_redir.c\
					src/pipex_util.c\
					src/pipex_split.c\
					src/pipex_free.c\
					src/pipex_ft.c\
					src/pipex_put_error.c\
					src/pipex_here_doc_v2.c\
					src/pipex_gnl.c\

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
