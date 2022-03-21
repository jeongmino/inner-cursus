/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 13:06:00 by junoh             #+#    #+#             */
/*   Updated: 2021/12/20 18:41:36 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	if (!*needle)
		return ((char *)haystack);
	if (len == 0)
		return (0);
	while (*haystack && (len - ft_strlen(needle) + 1) > 0)
	{
		i = 0;
		while (*(haystack + i) == *(needle + i))
		{
			i++;
			if (*(needle + i) == '\0')
				return ((char *)haystack);
		}
		haystack++;
		len--;
	}
	return (0);
}
