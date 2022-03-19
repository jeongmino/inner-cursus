/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_addr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 15:43:28 by junoh             #+#    #+#             */
/*   Updated: 2022/03/20 00:06:05 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_addr(char *arr)
{
	int	read_ret;
	int	i;

	ft_putchar_fd(arr[0], 1);
	ft_putchar_fd(arr[1], 1);
	read_ret = 2;
	i = 2;
	while (arr[i] == '0')
		i++;
	while (i < 18)
	{
		ft_putchar_fd(arr[i++], 1);
		read_ret += 1;
	}
	return (read_ret);
}

int	ft_print_p(va_list *ap)
{
	intptr_t	addr;
	char		buf[18];
	int			i;
	int			read_size;

	ft_memset(buf, 0, 18);
	addr = (intptr_t)va_arg(*ap, void *);
	if (addr == (intptr_t)0)
	{
		write(1, "0x0", 3);
		return (3);
	}
	buf[0] = '0';
	buf[1] = 'x';
	i = 0;
	while (i < 16)
	{
		buf[i + 2] = "0123456789abcdef"[addr >> (sizeof(addr) \
		* 2 - 1 - i) * 4 & 0xf];
		i++;
	}
	read_size = ft_print_addr(buf);
	return (read_size);
}
