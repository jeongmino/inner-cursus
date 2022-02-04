/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 15:34:12 by junoh             #+#    #+#             */
/*   Updated: 2022/01/24 22:00:06 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_full_line(char *left_string_buf)
{
	char	*str;
	int		idx;
	int		jdx;

	idx = 0;
	while (left_string_buf[idx] != '\0' && left_string_buf[idx] != '\n')
		idx++;
	str = malloc(sizeof(char) * (idx + 1 + (left_string_buf[idx] == '\n')));
	if (str == NULL)
		return (NULL);
	jdx = -1;
	while (jdx++ < idx)
		str[jdx] = left_string_buf[jdx];
	if (jdx == 0)
	{
		str[jdx] = '\n';
		jdx++;
	}
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
	save_point = (char *)malloc(ft_strlen(left_string_buf) - idx + 1);
	if (save_point == NULL)
		return (NULL);
	jdx = 0;
	while (left_string_buf[++idx] != '\0')
		save_point[jdx++] = left_string_buf[idx];
	save_point[jdx] = '\0';
	free(left_string_buf);
	return (save_point);
}

char	*ft_get_line_before_nl(char *left_string_buf, int fd)
{
	ssize_t	read_ret;
	char	*read_buffer;
	
	if (left_string_buf != NULL || ft_strchr(left_string_buf))
	   return (left_string_buf);	
	read_buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (read_buffer == NULL)
		return (NULL);
	while (1)
	{
		read_ret = read(fd, read_buffer, BUFFER_SIZE);
		if (read_ret == -1)
		{
			free(left_string_buf);
			free(read_buffer);
			return (NULL);
		}	
		read_buffer[read_ret] = '\0';
		left_string_buf = ft_strjoin(left_string_buf, read_buffer);
		if (!left_string_buf || ft_strchr(read_buffer, '\n') || read_ret == 0)
			break ;
	}
	free(read_buffer);
	return (left_string_buf);
}

char	*get_next_line(int fd)
{
	static char	*left_string_buf[4096];
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	left_string_buf[fd] = ft_get_line_before_nl(left_string_buf[fd], fd);
	if (left_string_buf[fd] == NULL)
		return (NULL);
	line = ft_get_full_line(left_string_buf[fd]);
	left_string_buf[fd] = ft_save_point(left_string_buf[fd]);
	return (line);
}
