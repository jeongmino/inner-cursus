/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 00:28:38 by junoh             #+#    #+#             */
/*   Updated: 2022/05/26 13:04:10 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (*str++)
		len++;
	return (len);
}

int	ft_strichr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	if (s[i] == c)
		return (i);
	else
		return (-1);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while ((n-- > 0) && !(!*s1 && !*s2))
	{
		if (*s1 != *s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		s1++;
		s2++;
	}
	return (0);
}

char	*ft_strndup(const char *s, int cpy_len)
{
	char	*tmp;
	int		len;

	len = cpy_len;
	tmp = malloc(sizeof(char) * (cpy_len + 1));
	if (tmp == NULL)
		return (NULL);
	while (cpy_len-- > 0)
	{
		*tmp = *s;
		tmp++;
		s++;
	}
	*tmp = '\0';
	return (tmp - len);
}

char	*ft_path_join(char *left_string_buf, char *read_buf)
{
	char	*str;
	int		idx;
	int		jdx;

	
	if (left_string_buf == NULL || read_buf == NULL)
		return (0);
	str = (char *)malloc(sizeof(char) * (ft_strlen(left_string_buf) \
	+ ft_strlen(read_buf) + 2));
	if (str == NULL)
		return (NULL);
	idx = -1;
	jdx = 0;
	while (left_string_buf[++idx] != '\0')
		str[idx] = left_string_buf[idx];
	str[idx++] = '/';
	while (read_buf[jdx] != '\0')
		str[idx++] = read_buf[jdx++];
	str[ft_strlen(left_string_buf) + ft_strlen(read_buf) + 1] = '\0';
	free(left_string_buf);
	return (str);
}
