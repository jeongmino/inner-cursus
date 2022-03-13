/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 15:02:28 by junoh             #+#    #+#             */
/*   Updated: 2021/12/08 15:01:19 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_numcount(int n)
{
	int	cnt;

	cnt = 0;
	if (n == 0)
		return (100);
	else if (n == -2147483648)
		return (-100);
	else if (n < 0)
	{
		n *= -1;
		cnt++;
	}
	while (n > 0)
	{
		n = n / 10;
		cnt++;
	}
	return (cnt);
}

static	char	*ft_convert(char *str, int n, int len)
{
	char	c;

	str[len--] = '\0';
	if (n == -2147483648)
	{
		str[len--] = '8';
		n = -214748364;
	}
	if (n < 0)
		n *= -1;
	if (n == 0)
	{
		str[0] = '0';
		return (str);
	}
	while (n > 0)
	{
		c = (n % 10) + '0';
		str[len--] = c;
		n = n / 10;
	}
	if (n == 0 && len == 0)
		str[0] = '-';
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;

	len = ft_numcount(n);
	if (len == 100)
		len = 1;
	else if (len == -100)
		len = 11;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	str = ft_convert(str, n, len);
	return (str);
}
