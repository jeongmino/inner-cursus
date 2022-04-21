/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpark <chpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 20:23:39 by chpark            #+#    #+#             */
/*   Updated: 2022/03/29 21:43:00 by chpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"

static int	swap_mecro(t_list *a)
{
	int	temp;

	temp = a->arr[0];
	a->arr[0] = a->arr[1];
	a->arr[1] = temp;
	return (1);
}

int	sa(t_stacks *stack)
{
	int	flag;

	flag = check_command(stack, "sa");
	if (flag == 0)
	{
		swap_mecro(stack->stack_a);
		ft_editstr(stack->command, 3);
		return (1);
	}
	else if (flag == 1)
	{
		swap_mecro(stack->stack_a);
		stack->command = ft_strjoin_push_swap(stack->command, "sa\n");
		return (1);
	}
	else if (flag == 2)
	{
		ss(stack);
		return (1);
	}
	else
		return (0);
}

int	sb(t_stacks *stack)
{
	int	flag;

	flag = check_command(stack, "sb");
	if (flag == 0)
	{
		swap_mecro(stack->stack_b);
		ft_editstr(stack->command, 3);
		return (1);
	}
	else if (flag == 1)
	{
		swap_mecro(stack->stack_a);
		stack->command = ft_strjoin_push_swap(stack->command, "sb\n");
		return (1);
	}
	else if (flag == 2)
	{
		ss(stack);
		return (1);
	}
	else
		return (0);
}

int	ss(t_stacks *stack)
{
	int	n;

	n = ft_strlen(stack->command);
	if (stack->command[n - 2] == 'a')
	{
		swap_mecro(stack->stack_b);
		ft_editstr(stack->command, 3);
		stack->command = ft_strjoin_push_swap(stack->command, "ss\n");
		return (1);
	}
	else if (stack->command[n - 2] == 'b')
	{
		swap_mecro(stack->stack_a);
		ft_editstr(stack->command, 3);
		stack->command = ft_strjoin_push_swap(stack->command, "ss\n");
		return (1);
	}
	else
		return (0);
}
