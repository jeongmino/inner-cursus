/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 23:09:33 by junoh             #+#    #+#             */
/*   Updated: 2022/03/16 17:15:51 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_parse_format(va_list ap, const char *format)
{
    int flag;
    int size;

    size = 0;
    while (*format != '\0')
    {
        flag = 0;
        if (*format != '%')
        {
            size++;
            ft_putchar_fd(*format++, 1);
        }
        else
        {
            size++;
            flag = ft_check_format(ap, ++format);
            if (flag == -1)
                break;
            size += flag;
        }
    }
    return (size);
}

int ft_check_format(va_list ap, const char *format)
{
    int read_size;

    read_size = 0;
	if (*format == '\0')
		return (-1);
	else if (*format == 'd' || *format == 'i')
        read_size = ft_print_di(ap);
	else if (*format == 'u')
		read_size = ft_print_u(ap);
	else if (*format == 'x' || *format == 'X')
		read_size = ft_print_x(ap, *format);
	else if (*format == 's')
		read_size = ft_print_s(ap);
	else if (*format == 'c')
		read_size = ft_print_c(ap);
	else if (*format == 'p')
		read_size = ft_print_p(ap);
	else if (*format == '%')
	{
		read_size = 1;
		ft_putchar_fd('%', 1);
	}
	else
	{
		read_size = 1;
		ft_putchar_fd(*format, 1);
	}
	return (read_size);
}
