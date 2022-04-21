NAME := push_swap

SRC_COMD := command/
SRC_SETD := setup/
SRC_SORTD := sort/
SRC_UTILD := util/
SRC_COM := $(addprefix $(SRC_COMD), command_check.c)\
			$(addprefix $(SRC_COMD), command_push.c)\
			$(addprefix $(SRC_COMD), command_swap.c)\
			$(addprefix $(SRC_COMD), command_rotate.c)\
			$(addprefix $(SRC_COMD), command_reverse_rotate.c)\
			$(addprefix $(SRC_COMD), command_check_utils.c)
SRC_SORT := $(addprefix $(SRC_SORTD), sort_five.c)\
			$(addprefix $(SRC_SORTD), sort_four.c)\
			$(addprefix $(SRC_SORTD), sort_three.c)\
			$(addprefix $(SRC_SORTD), sort_util.c)\
			$(addprefix $(SRC_SORTD), sort.c)
SRC_SET := $(addprefix $(SRC_SETD), setup.c)\
			$(addprefix $(SRC_SETD), setup_utils.c)
SRC_UTIL :=  $(addprefix $(SRC_UTILD), utils.c)\
				$(addprefix $(SRC_UTILD), utils2.c)\
				$(addprefix $(SRC_UTILD), utils3.c)
SRC := push_swap.c
OBJ := $(SRC_COM:.c=.o)\
		$(SRC_SORT:.c=.o)\
		$(SRC_SET:.c=.o)\
		$(SRC_UTIL:.c=.o)\
		$(SRC:.c=.o)
OBJ_D := ./obj/
OBJS := $(addprefix $(OBJ_D), $(OBJ))

MKDIR		=	$(shell mkdir $(OBJ_D) 2> /dev/null) \
				$(shell mkdir $(addprefix $(OBJ_D), $(SRC_COMD)) 2> /dev/null) \
				$(shell mkdir $(addprefix $(OBJ_D), $(SRC_SORTD)) 2> /dev/null) \
				$(shell mkdir $(addprefix $(OBJ_D), $(SRC_SETD)) 2> /dev/null) \
				$(shell mkdir $(addprefix $(OBJ_D), $(SRC_UTILD)) 2> /dev/null) \

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address
HEADER	= ./header/

AR = ar -rcs

all : $(MKDIR) $(NAME)

clean :
	rm -rf $(OBJ_D)

fclean : clean
	rm -rf $(NAME)

re : fclean all

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
*/%.o	: */%.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY : all clean fclean bonus re
