/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:33:02 by junoh             #+#    #+#             */
/*   Updated: 2021/12/22 13:11:34 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static long	ft_strtol(const char *str)
{
	long	sign;
	long	tmp;
	long	sum;

	while ((*str >= '\t' && *str <= '\r') || *str == ' ')
		str++;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str++ == '-')
			sign = -1;
	}
	sum = 0;
	tmp = 0;
	while (*str >= '0' && *str <= '9')
	{
		tmp = (sum * 10) + sign * (*str - '0');
		if (sum > 0 && tmp < 0)
			return (LONG_MAX);
		if (sum < 0 && tmp > 0)
			return (LONG_MIN);
		sum = tmp;
		str++;
	}
	return (sum);
}

int	ft_atoi(const char *str)
{
	return ((int)ft_strtol(str));
}
