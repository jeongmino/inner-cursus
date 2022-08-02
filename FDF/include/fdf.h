/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 15:38:39 by junoh             #+#    #+#             */
/*   Updated: 2022/08/02 16:34:32 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <unistd.h> 
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "../minilibx/mlx.h"

# define HEIGHT			1080
# define WIDTH			1920
# define X_ORIGIN       540
# define Y_ORIGIN       360
# define BUFFER_SIZE    256
# define EXIT_PAD       53
# define VAL_MOUSE      4
# define VAL_EXIT       2
# define VAL_MOUSE_HEEL_UP 5
# define VAL_MOUSE_HEEL_DOWN 4

enum	e_error
{
	MAP_ERROR,
	ERR_FDF_INIT
};

typedef struct s_coordinate
{
	double	x;
	double	y;
	double	z;
	int		color;
}	t_coordinate;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_map
{
	t_data			*map_data;
	t_coordinate	**coord;
	int				width;
	int				height;
	double			scale;
}	t_map;

/* ft_util.c */
int		ft_strlen(char	*str);
void	*ft_memalloc(size_t	size);
void	my_mlx_pixel_put(t_map *map, int x, int y, int color);

/* ft_free.c */
char	*ft_frees(char **strs, char *str);
void	ft_coord_free(t_map *map, int index);

/* gnl.c */
char	*get_next_line(int fd);

/* ft_split.c */
char	**ft_split(char const *s, char c);

/* ft_atoi_hex.c */
int		ft_atoi_hex(char *str, int *color);

/* ft_draw.c */
void	ft_draw(t_map *map);
void	ft_isometric(double *x, double *y, double z, double scale);

/* ft_init.c */
void	ft_init(t_map *map, int fd, char *file);

/* ft_open_file.c */
int		ft_open_file(char *file);

/* ft_put_error.c */
void	ft_perror(int err);

/* ft_parse.c */
void	ft_parse_map(t_map *map, int fd, int flag);
void	ft_print_coord(t_map *map);
void	ft_set_coord(t_map *map);

/* keyboard */
void	reset_img(t_map *map);
int		mouse_pressed(int button, int x, int y, t_map *map);
int		key_hook_esc(int key, t_map *map);

#endif
