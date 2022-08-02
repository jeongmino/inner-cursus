/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 17:34:20 by junoh             #+#    #+#             */
/*   Updated: 2022/08/01 20:12:29 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	ft_perror(int err)
{
	if (err == MAP_ERROR)
		perror("Map is not rectangular");
	else if (err == ERR_FDF_INIT)
		perror("Mlx Error");
	exit(1);
}
