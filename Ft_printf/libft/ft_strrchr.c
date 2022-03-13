/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 16:08:58 by junoh             #+#    #+#             */
/*   Updated: 2021/12/12 13:47:03 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*buffer;
	char	tmp;

	tmp = (char)c;
	buffer = 0;
	if (tmp == 0)
	{
		buffer = (char *)(s + ft_strlen(s));
		return (buffer);
	}
	while (*s)
	{
		if (*s == tmp)
			buffer = (char *)s;
		s++;
	}
	return (buffer);
}
