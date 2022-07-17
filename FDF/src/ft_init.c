/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 13:31:14 by junoh             #+#    #+#             */
/*   Updated: 2022/07/17 16:53:05 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void    ft_init(t_map *map, int fd)
{
    ft_var_set(map);
    ft_parse_map(map, fd, 0);
    map->coord = (t_coordinate**)malloc(sizeof(t_coordinate*) * map.height);
    if (map->coord == NULL)
        return(1);
    ft_parse_map(map, fd, 1);
    ft_map_init(map);
}

static void ft_map_init(t_map *map)
{
	if (!(map->map_data->mlx = mlx_init()))
		ft_perror(ERR_FDF_INIT);
	if (!(map->map_data->win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, "FdF")))
		ft_perror(ERR_FDF_INIT);
	if (!(map->map_data->img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT)))
		ft_perror(ERR_FDF_INIT);
	map->map_data->addr = mlx_get_data_addr(map->map_data->img, \
     &(map->map_data->bits_per_pixel), \
     &(map->map_data->line_length), &(map->map_data->endian));
	return ;
}