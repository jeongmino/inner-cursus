/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_letters.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 16:27:30 by junoh             #+#    #+#             */
/*   Updated: 2022/03/23 16:34:38 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_c(va_list *ap)
{
	int	c;

	c = va_arg(*ap, int);
	ft_putchar_fd((unsigned char)c, 1);
	return (1);
}

int	ft_print_s(va_list *ap)
{
	char	*str;
	char	*tmp;
	int		read_size;

	str = va_arg(*ap, char *);
	tmp = str;
	ft_putstr_fd(str, 1);
	if (str != NULL)
		read_size = ft_strlen(tmp);
	else
		read_size = ft_strlen("(null)");
	return (read_size);
}
