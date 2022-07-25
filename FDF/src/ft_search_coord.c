/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_coord.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 13:18:01 by junoh             #+#    #+#             */
/*   Updated: 2022/07/25 13:30:55 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void ft_move_parallel(t_map *map, int min_x, int max_y)
{
    int h;
    int w;

    min_x *= -1;
    max_y = max_y - HEIGHT;
    h = -1;
    while (++h < map->height)
    {
        w = -1;
        while (++w < map->width)
        {
            map->coord[h][w].x += min_x;
            map->coord[h][w].y -= max_y;
        }
    }
    return ;
}

void ft_search_coord(t_map *map)
{
    int min_x;
    int max_y;
    int h;
    int w;

    h = -1;
    min_x = 0;
    max_y = 0;
    while (++h < map->height)
    {
        w = -1;
        while (++w < map->width)
        {
            if (min_x > map->coord[h][w].x)
                min_x = map->coord[h][w].x;
            if (max_y < map->coord[h][w].y)
                max_y = map->coord[h][w].y;
        }
    }
    ft_move_parallel(map, min_x, max_y);
}