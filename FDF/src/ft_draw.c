/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 17:00:22 by junoh             #+#    #+#             */
/*   Updated: 2022/07/18 18:51:53 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	ft_isometric(int *x, int *y, int z)
{
	int	prev_x;
	int	prev_y;

	prev_x = *x;
	prev_y = *y;
	*x = (prev_x - prev_y) * cos(0.523599);
	*y = (prev_x + prev_y) * sin(0.523599) - z;
}

static void	my_mlx_pixel_put(t_map *map, int x, int y, int color)
{
	char	*dst;

	dst = map->map_data->addr + (y * map->map_data->line_length + \
	 x * (map->map_data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
// start_point (x0, y0), end_point(x1, y1)

static void ft_bresenham(t_map *map, t_coordinate s_point, t_coordinate e_point)
{
	int	dx;
	int	dy;
	int	x_step;
	int	p_next;
	
    dx = e_point.x - s_point.x;
    dy = e_point.y - s_point.y;
	p_next = 2 * dy - dx; // P1(초기값) 설정
	if (s_point.x < e_point.x)
		x_step = 1;
	else
		x_step = -1;
	while (s_point.x != e_point.x)
	{
		my_mlx_pixel_put(map, s_point.x, s_point.y, s_point.color);
		s_point.x += x_step;	// x는 매 좌표마다 증가
		if (p_next < 0) // Pnext 구하는 부분
			p_next += 2 * dy;
		else
		{
			p_next += 2 * dy - 2 * dx;
			s_point.y++;
		}
	}
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

void	ft_draw(t_map *map)
{
	int	w;
	int	h;

	h = -1;
	while (++h < map->height)
	{
		w = -1;
		while (++w < map->width)
		{	
		/*	if (w != map->width - 1)
				ft_bresenham(map, set_point(map, h, w), set_point(map, h, w + 1)); */
			if (h != map->height - 1)
			{
				ft_bresenham(map, set_point(map, h, w), set_point(map, h + 1, w));
				printf("%d %d %d %d\n", map->coord[h][w].x, map->coord[h][w].y, map->coord[h + 1][w].x, map->coord[h + 1][w].y);  
			}
		}	
	}
}