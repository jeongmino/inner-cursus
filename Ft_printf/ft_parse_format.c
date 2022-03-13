/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 23:09:33 by junoh             #+#    #+#             */
/*   Updated: 2022/03/14 00:01:53 by junoh            ###   ########.fr       */
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
    if (*format == 'd' || *format == 'i')
        read_size = ft_print_di()
}