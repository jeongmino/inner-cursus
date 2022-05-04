/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpark <chpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 14:20:16 by chpark            #+#    #+#             */
/*   Updated: 2022/05/04 16:44:41 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"

static int	find_min(t_list *a)
{
	int	min;
	int	i;
	int	ret;

	ret = 0;
	min = a->arr[0];
	i = 1;
	while (i < a->used_size)
	{
		if (a->arr[i] < min)
		{
			min = a->arr[i];
			ret = i;
		}
		i++;
	}
	return (ret);
}

static int	four_sort_sub(t_stacks *stack, int n)
{
	if (n < 2)
	{
		while (n-- > 0)
			ra(stack);
		if (is_sorted(stack->stack_a) == 0)
		{
			pb(stack);
			three_sort(stack);
			pa(stack);
		}
		return (1);
	}
	else
	{
		while (n++ < 4)
			rra(stack);
		if (is_sorted(stack->stack_a) == 0)
		{
			pb(stack);
			three_sort(stack);
			pa(stack);
		}
		return (1);
	}
}

int	four_sort(t_stacks *stack)
{
	int	n;

	n = find_min(stack->stack_a);
	if (is_sorted(stack->stack_a) == 0)
		return (four_sort_sub(stack, n));
	else
		return (1);
}
