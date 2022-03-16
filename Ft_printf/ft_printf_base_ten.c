/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_base_ten.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 19:36:43 by junoh             #+#    #+#             */
/*   Updated: 2022/03/16 16:25:19 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_numsize_count(long long num, int flag)
{
	int base;
	int	read_size;

	base = flag;
	read_size = 0;
	if (num < 0)
	{
		read_size++;
		num *= -1;
	}
	while (num != 0)
	{
		num = num / base;
		read_size++;
	}
	return (read_size);
}

int ft_print_di(va_list ap)
{
	int read_size;
	int read_num;

	read_num = va_arg(ap, int);
	read_size = ft_numsize_count((long long)read_num, 10);
	ft_putnbr_fd(read_num, 1);
	return (read_size);
}

int ft_print_u(va_list ap)
{
	int 			read_size;
	unsigned int 	read_num;

	read_num = va_arg(ap, unsigned int);
	read_size = ft_numsize_count((long long)read_num, 10);
	ft_putnbr_fd(read_num, 1);
	return (read_size);
}
