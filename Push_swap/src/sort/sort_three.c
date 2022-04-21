/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpark <chpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 14:36:14 by chpark            #+#    #+#             */
/*   Updated: 2022/04/20 17:48:24 by ojeongmin        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"
#include <stdlib.h>

int	three_sort(t_stacks *stack)
{
	int	*temp;

	temp = stack->stack_a->arr;
	if (temp[0] == 1)
	{
		if (temp[1] == 0)
			sa(stack);
		else
			rra(stack);
	}
	else if (temp[0] == 2)
	{
		if (temp[1] == 0)
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
