/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 19:44:55 by junoh             #+#    #+#             */
/*   Updated: 2022/01/20 15:59:55 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t		src_len;
	size_t		idx;

	src_len = 0;
    if (src != NULL)
	{
        while (src[src_len])
		src_len++;
    }
	idx = 0;
	while (idx + 1 < dstsize && idx < src_len)
	{
		dst[idx] = src[idx];
		idx++;
	}
	if (dstsize > 0)
		dst[idx] = '\0';
	return (src_len);
}

char	*ft_strchr(char *s, int c)
{

	if (s == NULL)
		return (0);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	else
		return (0);
}

int	ft_strlen(char *s)
{
	int	len;

	len = 0;
    if (s == NULL)
        return(0);
	while (*s++)
		len++;
	return (len);
}

size_t	ft_strlcat(char *dst, char *src, size_t dstsize)
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


char	*ft_strjoin(char *left_string_buf, char *read_buf)
{
	char	*str;
	int		len1;
	int		len2;

	if (left_string_buf == NULL)
	{
		left_string_buf = (char *)malloc(sizeof(char) * 1);
		left_string_buf[0] = '\0';
	}
	if (left_string_buf == NULL || read_buf == NULL)
		return (0);
	len1 = ft_strlen(left_string_buf);
	len2 = ft_strlen(read_buf);
	str = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (str == NULL)
		return (0);
	ft_strlcpy(str, left_string_buf, len1 + 1);
	ft_strlcat(str + len1, read_buf, len2 + 1);
	free(left_string_buf);
	return (str);
}
