/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:00:00 by junoh             #+#    #+#             */
/*   Updated: 2022/03/14 16:00:04 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *format, ...)
{
    va_list ap;
    int result;

    if (format == NULL)
        return (-1);
    va_start(ap, format);
    result = ft_parse_format(ap, format);
    va_end(ap);
    return (result);
}
