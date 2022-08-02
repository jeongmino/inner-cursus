/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 15:51:30 by junoh             #+#    #+#             */
/*   Updated: 2022/08/01 20:18:04 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static	void	ft_make_coord_arr(t_map *map)
{
	int	i;

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

void	ft_set_coord(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			map->coord[i][j].x = j * map->scale;
			map->coord[i][j].y = i * map->scale;
			ft_isometric(&(map->coord[i][j].x), \
					&(map->coord[i][j].y), \
					map->coord[i][j].z, \
					map->scale);
		}
	}
}

static	int	ft_make_coord(t_map *map, char **nums, int h)
{
	int	i;

	i = 0;
	while (i < map->width)
	{
		map->coord[h][i].color = 0x0FFF00;
		map->coord[h][i].z = ft_atoi_hex(nums[i], &(map->coord[h][i].color));
		i++;
	}
	return (0);
}

static	void	ft_count_size(t_map *map, char **str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	if (map->height == 0)
		map->width = len;
	if (len != map->width)
		ft_perror(MAP_ERROR);
	map->height++;
}

void	ft_parse_map(t_map *map, int fd, int flag)
{
	char	*line;
	char	**nums;
	int		h;

	h = 0;
	if (flag == 1)
		ft_make_coord_arr(map);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		nums = ft_split(line, ' ');
		if (flag == 1)
		{
			if (ft_make_coord(map, nums, h))
				ft_frees(nums, line);
		}
		if (flag != 1)
			ft_count_size(map, nums);
		ft_frees(nums, line);
		h++;
	}
	return ;
}
