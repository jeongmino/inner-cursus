/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_read.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:49:11 by junoh             #+#    #+#             */
/*   Updated: 2022/03/14 19:44:32 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int	ft_numsize_count(long long num, int flag)
{
	int base;
	int	read_size;

	base = flag;
	read_size = 0;
	if (num < 0)
	{
		read_size++;
		num *= -1;
	}
	while (num != 0)
	{
		num = num / base;
		read_size++;
	}
	return (read_size);
}
		


int ft_count_read(void *readed_arg)
{
	void *arg_cpy;


}

