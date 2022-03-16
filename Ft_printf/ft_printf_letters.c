/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_letters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 16:27:30 by junoh             #+#    #+#             */
/*   Updated: 2022/03/16 16:27:33 by junoh            ###   ########.fr       */
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

int	ft_print_s(va_list ap)
{
	char	*str;
	char	*tmp;
	int		read_size;

	str = va_arg(ap, char *);
	tmp = str;
	ft_putstr_fd(str, 1);
	read_size = ft_strlen(tmp);
	return (read_size);
}