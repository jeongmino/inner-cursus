# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junoh <junoh@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/28 15:38:19 by junoh             #+#    #+#              #
#    Updated: 2022/07/17 22:20:01 by junoh            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= 	fdf
CC 			= 	gcc 
RM 			= 	rm
CFLAGS		= 	-Wall -Wextra -Werror -g -fsanitize=address
RMFALGS 	= 	-f

SRC 		=	src/fdf.c\
				src/ft_atoi_hex.c\
				src/ft_draw.c\
				src/ft_free.c\
				src/ft_init.c\
				src/ft_open_file.c\
				src/ft_put_error.c\
				src/ft_split.c\
				src/ft_util.c\
				src/gnl.c\
				src/parse.c\

OBJ 		= 	$(SRC:.c=.o)

HEADER 		= 	include/fdf.h

MLX_FLAGS 	= 	-lmlx -framework OpenGL -framework AppKit

MATH_FLAGS 	= 	-lm

all: 			$(NAME)

$(NAME): 		$(OBJ)
				$(CC) ${CFLAGS} -o ${NAME} $^

%.o: %.c $(HEADER)
				$(CC) $(CFLAGS) $<

clean:
				$(RM) $(RMFALGS) $(OBJ)
		
fclean: 		clean
				$(RM) $(RMFALGS) $(OBJ) $(NAME)

re: 			fclean all

.PHONY:			all clean fclean r
