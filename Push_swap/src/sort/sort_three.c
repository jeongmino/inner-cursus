/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpark <chpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 14:36:14 by chpark            #+#    #+#             */
/*   Updated: 2022/04/21 15:29:31 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"
#include <stdlib.h>

int	three_sort(t_stacks *stack)
{
	if (stack->stack_a->arr[0] == 1)
	{
		if (stack->stack_a->arr[1] == 0)
			sa(stack);
		else
			rra(stack);
	}
	else if (stack->stack_a->arr[0] == 2)
	{
		if (stack->stack_a->arr[1] == 0)
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
