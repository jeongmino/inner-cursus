/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpark <chpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 16:11:26 by chpark            #+#    #+#             */
/*   Updated: 2022/05/04 16:44:25 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"

static int	ft_sort_fives(t_stacks *stack, int size)
{
	if (size == 2)
	{
		if (!ft_diff(stack->stack_a->arr[0], stack->stack_a->arr[1]))
		{
			sa(stack);
			return (1);
		}
		else
			return (1);
	}
	if (size == 3)
		return (three_sort(stack));
	if (size == 4)
		return (four_sort(stack));
	else
		return (five_sort(stack));
}

static void	find_max(t_stacks *stack, int max)
{
	int	n;
	int	i;

	i = 0;
	n = (max + 1) / 2;
	if (n == 0)
		return ;
	while (stack->stack_b->arr[i] != max)
		i++;
	if (i < n)
	{
		while (i-- > 0)
			rb(stack);
		return ;
	}
	else
	{
		while (((max + 1) - i) > 0)
		{
			rrb(stack);
			i++;
		}
		return ;
	}
}

static void	make_b(t_stacks *stack, int piv)
{
	int	num;

	num = 0;
	while (stack->stack_a->arr[0] != -1)
	{
		if (stack->stack_a->arr[0] <= num)
		{
			pb(stack);
			num++;
		}
		else if (stack->stack_a->arr[0] <= num + piv)
		{
			pb(stack);
			rb(stack);
			num++;
		}
		else
			ra(stack);
	}
}

static int	ft_sort_piv(t_stacks *stack, int size, int piv)
{
	int	i;

	make_b(stack, piv);
	i = 1;
	while (stack->stack_b->arr[0] != -1)
	{
		find_max(stack, size - i);
		pa(stack);
		i++;
	}
	return (1);
}

int	ft_sort(t_stacks *stack, int size)
{
	int	ret;

	ret = 0;
	if (size <= 5)
		ret = ft_sort_fives(stack, size);
	else if (size < 10)
		ret = ft_sort_piv(stack, size, 1);
	else if (size < 20)
		ret = ft_sort_piv(stack, size, 2);
	else if (size < 50)
		ret = ft_sort_piv(stack, size, 4);
	else if (size < 100)
		ret = ft_sort_piv(stack, size, 8);
	else if (size < 500)
		ret = ft_sort_piv(stack, size, 15);
	else
		ret = ft_sort_piv(stack, size, 30);
	return (ret);
}
