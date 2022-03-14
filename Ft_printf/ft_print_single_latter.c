/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_single_latter.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 21:11:15 by junoh             #+#    #+#             */
/*   Updated: 2022/03/14 21:28:11 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_print_c(va_list ap)
{
	char 	c;
	int 	flag;

	flag = va_arg(ap, int);
	if (ft_isascii(flag))
	{
		c = (char)flag;
		ft_putchar_fd(c, 1);
	}	
	return (1);
}
