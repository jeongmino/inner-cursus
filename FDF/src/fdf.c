
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
	
	(void)argc;
    fd = open(argv[1], O_RDONLY);
    ft_var_set(&map);
    ft_parse_map(&map, fd, 0);
    fd = open(argv[1], O_RDONLY);
    map.coord = (t_coordinate**)malloc(sizeof(t_coordinate*) * map.height);
    if (map.coord == NULL)
        return(1);
    ft_parse_map(&map, fd, 1);
 
}
