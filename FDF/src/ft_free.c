/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 17:01:43 by junoh             #+#    #+#             */
/*   Updated: 2022/07/17 21:56:10 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

char	*ft_frees(char **strs, char *str)
{
	int	i;

	i = 0;
	if (strs != NULL)
	{
		while (strs[i] != NULL)
			free(strs[i++]);
		free(strs[i]);
		free(strs);
	}
	if (str != NULL)
		free(str);
	return (NULL);
}

void	ft_coord_free(t_map *map, int index)
{
	int 			i;
	
	i = 0;
	while (i <= index)
		free(map->coord[i++]);
	free(map->coord);
}