/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 15:47:08 by junoh             #+#    #+#             */
/*   Updated: 2022/07/17 20:46:46 by junoh            ###   ########.fr       */
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
    t_map   *map;
    int     fd;
    
    if (argc != 2)
        return (1);
    fd = ft_open_file(argv[1]);
    ft_init(map, fd);
    ft_draw(map);
    mlx_loop(map->map_data->mlx);
}