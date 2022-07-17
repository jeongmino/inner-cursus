/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 13:14:38 by junoh             #+#    #+#             */
/*   Updated: 2022/07/17 13:28:57 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static int	ft_strncmp(const char *s1, const char *s2, size_t n)
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
// check file_name including NULL
static int  ft_check_file(char *file_name)
{
    char    *tmp;
    int     cnt;

    tmp = file_name;
    cnt = ft_strlen(tmp) - 4;
    while (cnt-- > 0)
        tmp++;
    return (ft_strncmp(".fdf", tmp, 5));
}   

int ft_open_file(char *file)
{
    int fd;
    
    if (ft_check_file(file))
        return (-1);
    fd = open(file, O_RDONLY);
    if (fd < 0)
        exit(1);
    return (fd);
}