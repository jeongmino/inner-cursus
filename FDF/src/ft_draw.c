/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 17:00:22 by junoh             #+#    #+#             */
/*   Updated: 2022/10/11 11:15:30 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	ft_isometric(double *x, double *y, double z, double scale)
{
	double	prev_x;
	double	prev_y;

	prev_x = *x;
	prev_y = *y;
	*x = round(((prev_x - prev_y) * cos((M_PI * 30) / 180)));
	*y = round((prev_x + prev_y) * sin((M_PI * 30) / 180)) - (z * scale);
	*x += X_ORIGIN;
	*y += Y_ORIGIN;
}

static t_coordinate	set_point(t_map *map, int i, int j)
{
	t_coordinate	point;

	point.x = map->coord[i][j].x;
	point.y = map->coord[i][j].y;
	point.z = 0;
	point.color = map->coord[i][j].color;
	return (point);
}

static void	same_x(t_map *map, t_coordinate s_point, t_coordinate e_point)
{
	double	y_flag;
	double	y;

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
	inc = (e_point.y - s_point.y) / (e_point.x - s_point.x);
	if (s_point.x == e_point.x)
		same_x(map, s_point, e_point);
	else
	{
		while (1)
		{
			y = inc * (x - (double)s_point.x) +(double)s_point.y;
			if (((int)x > 0 && WIDTH > (int)x) && (((int)y > 0 && HEIGHT > \
			(int)y)))
				my_mlx_pixel_put(map, (int)x, (int)y, s_point.color);
			x += (0.05 * x_flag);
			if (e_point.x - 0.1 <= x && x <= e_point.x)
				break ;
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
				draw_edge(map, set_point(map, h, w), set_point(map, h, w + 1));
			if (h != map->height - 1)
				draw_edge(map, set_point(map, h, w), set_point(map, h + 1, w));
		}	
	}
	mlx_put_image_to_window(map->map_data->mlx, map->map_data->win, \
	 map->map_data->img, 0, 0);
}
