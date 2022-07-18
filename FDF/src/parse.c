/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 15:51:30 by junoh             #+#    #+#             */
/*   Updated: 2022/07/18 18:46:09 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void ft_print_coord(t_map *map)
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

static  void ft_set_coord(t_map *map, char *str, int i, int j)
{
    map->coord[i][map->width - j].z = ft_atoi_hex(str, \
                &(map->coord[i][map->width - j].color));
    map->coord[i][map->width - j].x = GAP * ((map->width) - j);
    map->coord[i][map->width - j].y = GAP * i;
    ft_isometric(&(map->coord[i][map->width - j].x), \
                 &(map->coord[i][map->width - j].y), \
                   map->coord[i][map->width - j].z);  
} 

static  int ft_make_coord(t_map *map, char **lines)
{
    int j;
    int i;
    
    i = 0;
    while (i < map->height)
    {
        j = map->width;
        map->coord[i] = (t_coordinate *)ft_memalloc(sizeof(t_coordinate) * \
            map->width);
        if (*(map->coord) == NULL)
        {
            ft_coord_free(map, i);
            return (1);
        }
        while (j > 0)
        {
            ft_set_coord(map, lines[map->width - j], i, j);
            j--;   
        }
        i++;
    }
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
    
    while (1)
    {
        line = get_next_line(fd);
        if (line == NULL)
            break;
        line_nums = ft_split(line, ' ');
        if (flag == 1)
        {
            if(ft_make_coord(map, line_nums))
               ft_frees(line_nums, line); 
        }
        if (flag != 1)
            ft_count_size(map, line_nums);
        ft_frees(line_nums, line);
    }
    return ;
}