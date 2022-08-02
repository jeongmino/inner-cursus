NAME = fdf
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address
INCLUDES = -I./include
MLX_DIR=./minilibx
MLX_FLAGS = -L$(MLX_DIR) -lmlx -framework OpenGl -framework AppKit

#source
SRC_DIR = src/
SRC = 			gnl.c\
				ft_atoi_hex.c\
				ft_draw.c\
				ft_free.c\
				ft_init.c\
				ft_open_file.c\
				ft_put_error.c\
				ft_split.c\
				ft_util.c\
				fdf.c\
				parse.c\
				keyboard.c\


SRC_PREFIXED = $(addprefix $(SRC_DIR), $(SRC))

#objsm
OBJS = $(SRC_PREFIXED:.c=.o)

all : $(NAME)

%.o: %.c ./includes/fdf.h
	$(CC) $(CFLAGS) -I$(MLX_DIR) -c $< -o $@
$(NAME): $(OBJS)
	$(MAKE) -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(OBJS) -lm $(MLX_FLAGS) -o $(NAME)
	cp $(MLX_DIR)/libmlx.dylib libmlx.dylib
	@echo $(NAME) est construit

clean :
	@$(MAKE) clean -C $(MLX_DIR)
	@rm -rf $(OBJS)
	@echo cleaning

fclean : clean
	@rm -rf $(NAME)
	@rm -rf libmlx.dylib
	@echo "full clean"

re : fclean all

bonus : re

map42:all
	./fdf test_maps/42.map
map_simple:all
	./fdf test_maps/42.map
help	:
	@echo "all $(NAME) clean fclean re \033[0;32m map42 map_simple help\033[m"

.PHONY	: all clean fclean re help