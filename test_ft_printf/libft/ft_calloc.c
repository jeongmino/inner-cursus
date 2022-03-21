/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 18:10:50 by junoh             #+#    #+#             */
/*   Updated: 2022/01/02 16:56:40 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*tmp;
	size_t	len;

	len = count * size;
	if (len == 0)
		return (NULL);
	tmp = (void *)malloc(len);
	if (tmp == NULL)
		return (NULL);
	ft_bzero(tmp, len);
	return (tmp);
}
