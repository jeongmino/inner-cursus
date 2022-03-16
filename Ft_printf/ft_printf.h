/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 22:41:40 by junoh             #+#    #+#             */
/*   Updated: 2022/03/16 16:54:31 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include "./libft/libft.h"

int ft_printf(const char *format, ...);

int ft_parse_format(va_list ap, const char *format);

int ft_check_format(va_list ap, const char *format);

int	ft_numsize_count(long long num, int flag);

int ft_print_di(va_list ap);

int ft_print_u(va_list ap);

int	ft_print_x(va_list ap, char flag);

int	ft_print_c(va_list ap);

int	ft_print_s(va_list ap);

int	ft_print_addr(char *arr);

int	ft_print_p(va_list ap);

#endif
