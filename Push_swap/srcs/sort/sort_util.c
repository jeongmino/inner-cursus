/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpark <chpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 14:36:30 by chpark            #+#    #+#             */
/*   Updated: 2022/03/31 00:22:25 by chpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"

int	is_sorted(t_list *a)
{
	int	i;

	i = 0;
	while (i + 1 < a->used_size)
	{
		if (a->arr[i + 1] != (a->arr[i] + 1))
			return (0);
		i++;
	}
	return (1);
}

int	ft_diff(int s1, int s2)
{
	if (s1 > s2)
		return (0);
	else
		return (1);
}
