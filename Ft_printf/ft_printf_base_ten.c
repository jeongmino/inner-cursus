/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_base_ten.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 19:36:43 by junoh             #+#    #+#             */
/*   Updated: 2022/03/20 00:10:33 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_numsize_count(long long num, int flag)
{
	int	base;
	int	read_size;

	base = flag;
	if (num == 0)
		return (1);
	else if (num == -2147483648)
		return (11);
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

int	ft_print_di(va_list *ap)
{
	int	read_size;
	int	read_num;

	read_num = va_arg(*ap, int);
	read_size = ft_numsize_count((long long)read_num, 10);
	ft_putnbr_fd(read_num, 1);
	return (read_size);
}

int	ft_print_u(va_list *ap)
{
	int				read_size;
	unsigned int	read_num;

	read_num = (unsigned int)va_arg(*ap, unsigned int);
	read_size = ft_numsize_count((long long)read_num, 10);
	ft_put_unsigned_nbr(read_num);
	return (read_size);
}

void	ft_put_unsigned_nbr(unsigned int n)
{
	if (n < 10)
	{
		ft_putchar_fd(n + '0', 1);
		return ;
	}
	else
		ft_put_unsigned_nbr(n / 10);
	ft_putchar_fd((n % 10) + '0', 1);
	return ;
}
