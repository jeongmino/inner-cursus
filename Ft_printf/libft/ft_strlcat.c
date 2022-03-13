/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 12:14:52 by junoh             #+#    #+#             */
/*   Updated: 2021/12/12 15:10:30 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	total;
	size_t	srclen;
	size_t	i;

	total = 0;
	while (total < dstsize && dst[total])
		total++;
	srclen = ft_strlen(src);
	i = total;
	while (*src != '\0' && i + 1 < dstsize)
		*(dst + i++) = *src++;
	if (i < dstsize)
		dst[i] = '\0';
	return (total + srclen);
}
