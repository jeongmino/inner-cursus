/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 14:44:01 by junoh             #+#    #+#             */
/*   Updated: 2022/07/17 19:41:35 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	ft_atoi_hex(char *str, int *color)
{
	int sign;
	int	sum;

	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str++ == '-')
			sign = -1;
	}
	sum = 0;
	while (*str >= '0' && *str <= '9')
	{
		sum = (sum * 10) + sign * (*str - '0');
		str++;
	}
    if (*str == ',')
        ft_atohex(++str, color);
	return (sum);
}

static char	ft_toupper(char c)
{
	if (c >= 97 && c <= 122)
		return (c - 32);
	else
		return (c);
}

static int	ft_isdigit_base(char c)
{
	const char *digit = "0123456789ABCDEF";
	int			i;
	
	i = 0;
	while (i < 16)
	{
		if (digit[i] == ft_toupper(c))
			return(i);
		i++;
	}
	return (-1);
}

static void	ft_atohex(char *str, int *color)
{
    int	sum;

	sum = 0x0;
	while (*str == '0' || *str == 'x' || *str == 'X')
		str++;
	while ((*str >= '0' && *str <= '9') || (*str >= 'a' && *str <= 'f') || \
	(*str >= 'A' && *str <= 'F'))
	{
		sum = sum * 16 + ft_isdigit_base(*str);
		str++;
	}
	color = sum;
}