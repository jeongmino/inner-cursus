/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 13:02:39 by junoh             #+#    #+#             */
/*   Updated: 2022/08/01 16:00:35 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	reset_img(t_map *map)
{
	if (map->map_data->img)
		mlx_destroy_image(map->map_data->mlx, map->map_data->img);
	if (map->map_data->mlx)
		mlx_clear_window(map->map_data->mlx, map->map_data->win);
	map->map_data->img = mlx_new_image(map->map_data->mlx, WIDTH, HEIGHT);
	map->map_data->addr = mlx_get_data_addr(map->map_data->img, \
     &(map->map_data->bits_per_pixel), \
     &(map->map_data->line_length), &(map->map_data->endian));	
}

int	mouse_pressed(int button, int x, int y, t_map *map)
{
	(void)x;
	(void)y;
	(void)button;
	reset_img(map);
	if (button == VAL_MOUSE_HEEL_DONW && map->scale > 0.00001)
		map->scale -= map->scale * 0.1;
	else if (button == VAL_MOUSE_HEEL_UP && map->scale < 10000)
		map->scale += map->scale * 0.1; 

	ft_draw(map);
	return (1);
}
