/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 15:51:30 by junoh             #+#    #+#             */
/*   Updated: 2022/07/25 13:31:21 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void ft_print_coord(t_map *map) // 마지막에는 삭제할 함수
{
    int w;
    int h = 0;

    while (h < map->height)
    {
        w = 0;
        while (w < map->width)
        {
            printf("x = %d, y = %d, z = %d, color = %d\n", map->coord[h][w].x, \
            map->coord[h][w].y, map->coord[h][w].z, map->coord[h][w].color);
            w++;
        }
        h++;
    }
    return ;
}

static void ft_make_coord_arr(t_map *map)
{
    int i;

    i = 0;
    while (i < map->height)
    {
        map->coord[i] = (t_coordinate *)ft_memalloc(sizeof(t_coordinate) * \
            map->width);
        if (map->coord[i] == NULL)
        {
            ft_coord_free(map, i);
            exit (1);
        }
        i++;
    }
    return ;
}

static  int ft_set_coord(t_map *map, char *str, int j, int i)
{
    map->coord[i][j].color = 0x0FFF00;
    map->coord[i][j].z = ft_atoi_hex(str, \
                &(map->coord[i][j].color));
    map->coord[i][j].x = GAP * j;
    map->coord[i][j].y = GAP * i;
    ft_isometric(&(map->coord[i][j].x), \
                 &(map->coord[i][j].y), \
                   map->coord[i][j].z);
    //map->coord[i][j].x += 350;
    //map->coord[i][j].y += 350;
    return (1);
} 

static  int ft_make_coord(t_map *map, char **lines, int h)
{
    int i;
    int cnt = 0;
    i = 0;
    while (i < map->width)
    {
        ft_set_coord(map, lines[i], i, h);
        i++;
    }
    printf("cnt = %d\n", cnt);
    return (0);
}

static  void    ft_count_size(t_map *map, char **str)
{
    int len;
    
    len = 0;
    while (str[len])
        len++;
    if (map->height == 0)
        map->width = len;
    if (len != map->width)
            ft_perror(MAP_ERROR);
    map->height++;
}

void    ft_parse_map(t_map *map, int fd, int flag)
{
    char    *line;
    char    **line_nums;
    int     h;

    h = 0;
    if (flag == 1)
        ft_make_coord_arr(map);
    while (1)
    {
        line = get_next_line(fd);
        if (line == NULL)
            break;
        line_nums = ft_split(line, ' ');
        if (flag == 1)
        {
            if(ft_make_coord(map, line_nums, h++))
               ft_frees(line_nums, line); 
        }
        if (flag != 1)
            ft_count_size(map, line_nums);
        ft_frees(line_nums, line);
    }
    return ;
}