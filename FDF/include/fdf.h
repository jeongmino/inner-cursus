/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 15:38:39 by junoh             #+#    #+#             */
/*   Updated: 2022/07/18 18:47:09 by junoh            ###   ########.fr       */
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
# define BUFFER_SIZE    256
# define GAP            35

enum    e_error
{
    MAP_ERROR,
    ERR_FDF_INIT
};

typedef struct  s_coordinate
{
    int x;
    int y;
    int z;
    int color;
}               t_coordinate;

typedef struct  s_data
{
    void    *mlx;
    void    *win;
    void    *img;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
}               t_data;

typedef struct  s_map
{
    t_data          *map_data;         
    t_coordinate    **coord;
    int             width;
    int             height;
    int             map[2];
    
}               t_map;


/* ft_util.c */
int     ft_strlen(char  *str);
void    *ft_memalloc(size_t size);

/* ft_free.c */
char	*ft_frees(char **strs, char *str);
void	ft_coord_free(t_map *map, int index);

/* gnl.c */
char	*get_next_line(int fd);

/* ft_split.c */
char	**ft_split(char const *s, char c);

/* ft_atoi_hex.c */
int	    ft_atoi_hex(char *str, int *color);

/* ft_draw.c */
void	ft_draw(t_map *map);
void	ft_isometric(int *x, int *y, int z);

/* ft_init.c */
void    ft_init(t_map *map, int fd, char *file);

/* ft_open_file.c */
int     ft_open_file(char *file);

/* ft_put_error.c */
void	ft_perror(int err);

/* ft_parse.c */
void    ft_parse_map(t_map *map, int fd, int flag);
void    ft_print_coord(t_map *map);
#endif