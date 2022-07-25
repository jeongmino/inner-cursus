/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 13:31:14 by junoh             #+#    #+#             */
/*   Updated: 2022/07/22 15:03:04 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void ft_map_init(t_map *map)
{
	if (!(map->map_data->mlx = mlx_init()))
		ft_perror(ERR_FDF_INIT);
    printf("pass mlx\n");
	if (!(map->map_data->win = mlx_new_window(map->map_data->mlx, WIDTH, HEIGHT, "FdF")))
		ft_perror(ERR_FDF_INIT);
    printf("pass win\n");
	if (!(map->map_data->img = mlx_new_image(map->map_data->mlx, WIDTH, HEIGHT)))
		ft_perror(ERR_FDF_INIT);
    printf("pass img\n");
	map->map_data->addr = mlx_get_data_addr(map->map_data->img, \
     &(map->map_data->bits_per_pixel), \
     &(map->map_data->line_length), &(map->map_data->endian));
    printf("pass addr\n");
	return ;
}

void    ft_init(t_map *map, int fd, char *file)
{
    ft_parse_map(map, fd, 0);
    map->coord = (t_coordinate**)ft_memalloc(sizeof(t_coordinate*) \
     * map->height);
    if (map->coord == NULL)
        exit(1);
    fd = open(file, O_RDONLY);
    if (fd < 0)
        exit(1); 
    ft_parse_map(map, fd, 1);
    map->map_data = (t_data*)ft_memalloc(sizeof(t_data));
    if (map->map_data == NULL)
    {
        ft_coord_free(map, map->height - 1);
        exit(1);
    }
    ft_map_init(map);
}