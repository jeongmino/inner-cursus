/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 15:38:39 by junoh             #+#    #+#             */
/*   Updated: 2022/07/17 17:52:39 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h> 
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

# define HEIGHT			1080
# define WIDTH			1920
# define BUFFER_SIZE    256
# define GAP            35
enum    e_error
{
    MAP_ERROR
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
int ft_strlen(char  *str);

/* ft_free.c */
char	*ft_frees(char **strs, char *str);

/* gnl.c */
char	*get_next_line(int fd)

/* ft_split.c */
char	**ft_split(char const *s, char c);

#endif
