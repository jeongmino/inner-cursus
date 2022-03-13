/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 23:09:33 by junoh             #+#    #+#             */
/*   Updated: 2022/03/13 23:20:46 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_parse_format(va_list ap, const char *format)
{
    char *format_ptr;
    int size;
    
    size = 0;
    format_ptr = NULL;
    while (*format != '\0')
    {
        if (*format != '%')
        {
            size++;
            ft_putchar_fd(*format++, 1);
        }
        else
        {
            
        }
    }    
}
