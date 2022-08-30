/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 15:47:08 by junoh             #+#    #+#             */
<<<<<<< HEAD:FDF/src/main.c
/*   Updated: 2022/07/16 20:13:31 by junoh            ###   ########.fr       */
=======
/*   Updated: 2022/08/01 18:55:11 by junoh            ###   ########.fr       */
>>>>>>> 9a060b2ee0ec7760518e90b46eb019288d246923:FDF/src/fdf.c
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

static void	ft_var_set(t_map *map)
{
	ft_memset(map, 0, sizeof(t_map));
	map->scale = 30;
}

int	main(int argc, char **argv)
{
	t_map	map;
	int		fd;

<<<<<<< HEAD:FDF/src/main.c
    fd = open(argv[1], O_RDONLY);
    ft_var_set(&map);
    ft_parse_map(&map, fd, 0);
    fd = open(argvp[1], O_RDONLY);
    map.coord = (t_coordinate**)malloc(sizeof(t_coordinate*) * map.height);
    if (map.coord == NULL)
        return(1);
    ft_parse_map(&map, fd, 1);
 
=======
	if (argc != 2)
		return (1);
	fd = ft_open_file(argv[1]);
	ft_var_set(&map);
	ft_init(&map, fd, argv[1]);
	ft_draw(&map);
	mlx_hook(map.map_data->win, VAL_MOUSE, 0, mouse_pressed, &map);
	mlx_hook(map.map_data->win, VAL_EXIT, 0, key_hook_esc, &map);
	mlx_loop(map.map_data->mlx);
>>>>>>> 9a060b2ee0ec7760518e90b46eb019288d246923:FDF/src/fdf.c
}
