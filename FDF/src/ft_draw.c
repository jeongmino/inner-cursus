/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 17:00:22 by junoh             #+#    #+#             */
/*   Updated: 2022/07/22 1 by j31unoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	ft_isometric(int *x, int *y, int z, int scale)
{
	int	prev_x;
	int	prev_y;
	
	prev_x = *x;
	prev_y = *y;
	*x = (prev_x - prev_y) * cos(0.523599);
	*y = (prev_x + prev_y) * sin(0.523599) - (z * scale);
	*x += X_ORIGIN;
	*y += Y_ORIGIN;
}

static void	my_mlx_pixel_put(t_map *map, int x, int y, int color)
{
	char	*dst;

	dst = map->map_data->addr + (y * map->map_data->line_length + \
	 x * (map->map_data->bits_per_pixel / 8));
	 (void)color;
	*(unsigned int*)dst = 0x0fff00;
}

static t_coordinate set_point(t_map *map, int i, int j)
{
	t_coordinate point;
	
	point.x = map->coord[i][j].x;
	point.y = map->coord[i][j].y;
	point.z = 0;
	point.color = map->coord[i][j].color;
//	printf("x = %d, y = %d, color = %d\n", point.x, point.y, point.color);
	return (point);
}

static void	same_x(t_map *map, t_coordinate s_point, t_coordinate e_point)
{
	int	y_flag;
	int	y;
	
	y_flag = 1;
	y = s_point.y;
	if (s_point.y > e_point.y)
		y_flag = -1;
	while (y != e_point.y)
	{
		my_mlx_pixel_put(map, s_point.x, y, s_point.color);
		y += y_flag;
	}
}

static void	draw_edge(t_map *map, t_coordinate s_point, t_coordinate e_point)
{
	double			x_flag;
	double			x;
	double			y;
	double			inc;

	x = s_point.x;
	x_flag = 1;
	if (s_point.x > e_point.x)
		x_flag = -1;
	if (s_point.x == e_point.x)
		same_x(map, s_point, e_point);
	else
	{
		while ((int)x != e_point.x)
		{
			inc = ((double)e_point.y - (double)s_point.y) / \
			 ((double)e_point.x - (double)s_point.x);
			y = inc * (x - (double)s_point.x) +(double)s_point.y; //직선의방정식
			if ((x > 0 && WIDTH > x) && (y > 0 && HEIGHT > y))
				my_mlx_pixel_put(map, x, y, s_point.color);	
			x += (0.05 * x_flag);
		}
	}
}

void	ft_draw(t_map *map)
{
	int	w;
	int	h;

	ft_set_coord(map);
	h = -1;
	while (++h < map->height)
	{
		w = -1;
		while (++w < map->width)
		{	
			if (w != map->width - 1)
				draw_edge(map,set_point(map, h, w), set_point(map, h, w + 1));
			if (h != map->height - 1)
				draw_edge(map,set_point(map, h, w), set_point(map, h + 1, w));
		}	
	}
	mlx_put_image_to_window(map->map_data->mlx, map->map_data->win, \
     map->map_data->img, 0, 0);
}