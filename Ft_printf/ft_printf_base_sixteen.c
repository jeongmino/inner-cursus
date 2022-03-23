/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_base_sixteen.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 19:44:24 by junoh             #+#    #+#             */
/*   Updated: 2022/03/21 23:35:43 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_x(va_list *ap, char flag)
{
	char			hexa_arr[8];
	unsigned int	hexa_num;
	unsigned int	div;
	int				i;

	hexa_num = va_arg(*ap, unsigned int);
	i = 0;
	while (i < 8)
	{
		div = hexa_num % 16;
		hexa_arr[i] = "0123456789ABCDEF"[div];
		if (flag == 'x')
			hexa_arr[i] = (char)ft_tolower((int)hexa_arr[i]);
		hexa_num = hexa_num / 16;
		i++;
	}
	return (ft_printf_arr(hexa_arr));
}

int	ft_printf_arr(char *arr)
{
	int	read_size;

	read_size = 0;
	arr += 7;
	while (*arr == '0')
		arr--;
	if (*arr == '\0')
	{
		ft_putchar_fd('0', 1);
		read_size = 1;
	}
	while (*arr != '\0')
	{
		write(1, arr--, 1);
		read_size++;
	}
	return (read_size);
}
