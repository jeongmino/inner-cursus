/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 15:47:08 by junoh             #+#    #+#             */
/*   Updated: 2022/07/14 15:18:46 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static	void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)b;
	while (len--)
		*ptr++ = (unsigned char)c;
	return (b);
}

static void ft_var_set(t_map *map)
{
    ft_memset(map, 0, sizeof(t_map));
}

int main(int argc, char **argv)
{
    t_map   map;
    int     fd;

    fd = open(argv[1], O_RDONLY);
    ft_var_set(&map);
    ft_parse_map(&map, fd, 0);
    fd = open(argvp[1], O_RDONLY);
    map.coord = (t_coordinate**)malloc(sizeof(t_coordinate*) * map.height);
    if (map.coord == NULL)
        return(1);
    ft_parse_map(&map, fd, 1);
    
}