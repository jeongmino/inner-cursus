/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 16:57:18 by junoh             #+#    #+#             */
/*   Updated: 2022/07/18 16:01:53 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int ft_strlen(char  *str)
{
    int i;

    if (str == NULL)
		return (0);
    i = 0;
    while (str[i])
        i++;
    return (i);
}

static void ft_bzero(void *s, size_t n)
{
	unsigned char *ptr;

	ptr = (unsigned char *)s;
	while (n--)
		*ptr++ = '\0';
}

void	*ft_memalloc(size_t size)
{
	void *ptr;

	if ((ptr = malloc(size)))
		ft_bzero(ptr, size);
	return (ptr);
}