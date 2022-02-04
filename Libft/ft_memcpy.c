/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 14:37:50 by junoh             #+#    #+#             */
/*   Updated: 2021/12/12 13:39:30 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char				*ptr_dst;
	const unsigned char			*ptr_src;

	ptr_dst = (unsigned char *)dst;
	ptr_src = (const unsigned char *)src;
	if (ptr_dst == ptr_src)
		return (ptr_dst);
	while (n--)
		*ptr_dst++ = *ptr_src++;
	return (dst);
}
