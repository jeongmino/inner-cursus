/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 19:44:55 by junoh             #+#    #+#             */
/*   Updated: 2022/02/05 21:24:22 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	while (*s++)
		len++;
	return (len);
}

char	*ft_strjoin(char *left_string_buf, char *read_buf)
{
	char	*str;
	int		idx;
	int		jdx;

	if (left_string_buf == NULL)
	{
		left_string_buf = (char *)malloc(sizeof(char) * 1);
		left_string_buf[0] = '\0';
	}
	if (left_string_buf == NULL || read_buf == NULL)
		return (0);
	str = (char *)malloc(sizeof(char) * (ft_strlen(left_string_buf) \
	+ ft_strlen(read_buf) + 1));
	if (str == NULL)
		return (NULL);
	idx = -1;
	jdx = 0;
	while (left_string_buf[++idx] != '\0')
		str[idx] = left_string_buf[idx];
	while (read_buf[jdx] != '\0')
		str[idx++] = read_buf[jdx++];
	str[ft_strlen(left_string_buf) + ft_strlen(read_buf)] = '\0';
	free(left_string_buf);
	return (str);
}
