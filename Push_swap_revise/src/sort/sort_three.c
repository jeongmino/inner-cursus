/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpark <chpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 14:36:14 by chpark            #+#    #+#             */
/*   Updated: 2022/05/03 13:36:39 by ojeongmin        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"
#include <stdio.h>

static	int	three_sorting(t_stacks *stack, int n)
{
	if (stack->stack_a->arr[0] == n - 2) // == 1
	{
		if (stack->stack_a->arr[1] == n - 3) // == 0
			sa(stack);
		else
			rra(stack);
	}
	else if (stack->stack_a->arr[0] == n - 1) // == 2
	{
		if (stack->stack_a->arr[1] == n - 3) // == 0
			ra(stack);
		else
		{
			sa(stack);
			rra(stack);
		}
	}
	else
	{
		sa(stack);
		ra(stack);
	}
	return (1);
}

int	three_sort(t_stacks *stack)
{
	int		count;
	int		i;

	count = 0;
	i = 0;
	while (stack->stack_a->arr[i])
	{
		if (stack->stack_a->arr[i] == -1)
			count++;
		i++;
	}
	three_sorting(stack, count + 3);
	return (1);
}
