/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_addr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 15:43:28 by junoh             #+#    #+#             */
/*   Updated: 2022/03/17 13:41:25 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_addr(char *arr)
{
	int read_ret;
	int	i;

	ft_putchar_fd(arr[0], 1);
	ft_putchar_fd(arr[1], 1);
	read_ret = 2;
	i = 2;
	while (arr[i])
	{
		if (arr[i] != '0')
		{
			ft_putchar_fd(arr[i], 1);
			read_ret++;
		}
		i++;
	}
	return (read_ret);
}

int	ft_print_p(va_list *ap)
{
	intptr_t	addr;
	char		buf[18];
	int			i;
	int			read_size;

	addr = (intptr_t)va_arg(*ap, void *);
	buf[0] = '0';
	buf[1] = 'x';
	i = 0;
	while (i < 16)
	{
		buf[i + 2] = "0123456789abcdef"[addr >> (sizeof(addr) * 2 - 1 - i) * 4 & 0xf];
		i++;
	}
	read_size = ft_print_addr(buf);
	return (read_size);
}
