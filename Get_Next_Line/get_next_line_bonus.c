/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 21:20:55 by junoh             #+#    #+#             */
/*   Updated: 2022/06/28 16:46:10 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_get_full_line(char *left_string_buf)
{
	char	*str;
	int		idx;
	int		jdx;

	idx = 0;
	while (left_string_buf[idx] != '\0' && left_string_buf[idx] != '\n')
		idx++;
	str = malloc(sizeof(char) * (idx + 2));
	if (str == NULL)
		return (NULL);
	jdx = -1;
	while (jdx++ < idx)
		str[jdx] = left_string_buf[jdx];
	str[jdx] = '\0';
	return (str);
}

char	*ft_save_point(char *left_string_buf)
{
	char	*save_point;
	int		idx;
	int		jdx;

	idx = 0;
	while (left_string_buf[idx] != '\0' && left_string_buf[idx] != '\n')
		idx++;
	if (!left_string_buf[idx])
	{
		free(left_string_buf);
		return (NULL);
	}
	save_point = (char *)malloc(ft_strlen(left_string_buf) - idx + 1);
	if (save_point == NULL)
		return (NULL);
	idx++;
	jdx = 0;
	while (left_string_buf[idx] != '\0')
		save_point[jdx++] = left_string_buf[idx++];
	save_point[jdx] = '\0';
	free(left_string_buf);
	return (save_point);
}

char	*ft_get_line_nl(char *left_string_buf, char *read_buf, int fd)
{
	ssize_t	read_ret;

	read_ret = 1;
	while (!(ft_strchr(left_string_buf, '\n')) && read_ret)
	{
		read_ret = read(fd, read_buf, BUFFER_SIZE);
		if (read_ret == -1)
		{
			free(left_string_buf);
			free(read_buf);
			return (NULL);
		}
		read_buf[read_ret] = '\0';
		left_string_buf = ft_strjoin(left_string_buf, read_buf);
		if (!left_string_buf || (!read_ret && !*read_buf && !*left_string_buf))
		{
			if (left_string_buf)
				free(left_string_buf);
			left_string_buf = NULL;
			free(read_buf);
			return (NULL);
		}
	}
	free(read_buf);
	return (left_string_buf);
}

char	*get_next_line(int fd)
{
	static char	*left_string_buf[4096];
	char		*read_buf;
	char		*line;

	if (fd < 0)
		return (NULL);
	read_buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (read_buf == NULL)
		return (NULL);
	left_string_buf[fd] = ft_get_line_nl(left_string_buf[fd], read_buf, fd);
	if (left_string_buf[fd] == NULL)
		return (NULL);
	line = ft_get_full_line(left_string_buf[fd]);
	left_string_buf[fd] = ft_save_point(left_string_buf[fd]);
	return (line);
}
