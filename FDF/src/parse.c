/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 15:51:30 by junoh             #+#    #+#             */
/*   Updated: 2022/06/28 17:44:28 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static char **ft_make_coord()
{
    
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

void    ft_parse_map(t_map *map, int fd)
{
    char    *line;
    char    **line_nums;
    int     tmp;
    
    while (1)
    {
        line = get_next_line(fd);
        if (line == NULL)
            break;
        line_nums = ft_split(line, ' ');
        ft_count_size(map, line_nums);
    }
}