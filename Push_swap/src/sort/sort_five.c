/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpark <chpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 13:47:11 by chpark            #+#    #+#             */
/*   Updated: 2022/04/07 15:53:10 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"

static int	five_sort_sub(t_stacks *stack, int count)
{
	if (count < 2)
	{
		while (count-- > 0)
			ra(stack);
		if (is_sorted(stack->stack_a) == 0)
		{
			pb(stack);
			four_sort(stack);
			pa(stack);
		}
		return (1);
	}
	else
	{
		while (count++ < 5)
			rra(stack);
		if (is_sorted(stack->stack_a) == 0)
		{
			pb(stack);
			four_sort(stack);
			pa(stack);
		}
		return (1);
	}
}

int	five_sort(t_stacks *stack)
{
	int		count;
	t_list	*a;

	a = stack->stack_a;
	count = 0;
	if (is_sorted(a) == 0)
	{
		while (count < a->used_size)
		{
			if (a->arr[count] == 0)
				return (five_sort_sub(stack, count));
			else
				count++;
		}
		return (0);
	}
	else
		return (1);
}
