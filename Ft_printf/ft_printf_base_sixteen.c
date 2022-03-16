/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_base_sixteen.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 19:44:24 by junoh             #+#    #+#             */
/*   Updated: 2022/03/16 16:43:22 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_x(va_list ap, char flag)
{
	char			hexa_arr[8];
	unsigned int	hexa_num;
	unsigned int	div;
	int				i;

	hexa_num = va_arg(ap, unsigned int);
	ft_memset(hexa_arr, 0, 8);
	i = 0;
	while (hexa_num != 0 || i < 8)
	{
		div = hexa_num % 16;
		hexa_arr[i] = "0123456789ABCDEF"[div];
		if (flag == 'x')
			hexa_arr[i] = (char)ft_tolower((int)hexa_arr[i]);
		hexa_num = hexa_num / 16;
		i++;
	}
	while (i >= 0)
		ft_putchar_fd(hexa_arr[i--], 1);
	return (ft_strlen(hexa_arr));
}
