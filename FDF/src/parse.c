/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 15:51:30 by junoh             #+#    #+#             */
/*   Updated: 2022/07/16 13:33:28 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static  int ft_make_coord(t_map *map, char **lines)
{
    int width;

    width = map->width;
    while (*lines)
    {
        *(map->coord) = (t_coordinate*)malloc(sizeof(t_coordinate));
        if (map->*coord == NULL)
            return (1);
        while (width--)
        {
            **(map->coord)->z = ft_atoi_hex(*lines);
            **(map->coord)->x++;
            **(map->coord)->y++;
            **(map->coord)++;
        }
        *(map->coord)++;
        *lines++;
    }
}

static  void    ft_count_size(t_map *map, char **str)
{
    int len;
    int tmp;
    
    len = 0;
    while (str[0][len])
        len++;
    if (map->height == 0)
        map->width = len;
    else
        tmp = len;
    if (tmp != map->width)
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
        if (flag)
            if(ft_make_coord(map, line_nums))
               ft_frees(line_nums, line); 
        ft_count_size(map, line_nums);
        ft_frees(line_nums, line);
    }
    return ;
}