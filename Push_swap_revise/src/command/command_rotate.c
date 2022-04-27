/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpark <chpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 17:50:05 by chpark            #+#    #+#             */
/*   Updated: 2022/03/30 17:50:55 by chpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"
#include <unistd.h>

int	rotate_mecro(t_list *a)
{
	int	i;
	int	temp;

	i = 0;
	if (a->used_size <= 1)
		return (0);
	temp = a->arr[i];
	while (i < a->used_size - 1)
	{
		a->arr[i] = a->arr[i + 1];
		i++;
	}
	a->arr[i] = temp;
	return (1);
}

int	ra(t_stacks *stack)
{
	int	flag;

	flag = check_command(stack, "ra");
	if (flag == -1)
		exit (write(1, "error", 5));
	if (flag == 0)
		return (1);
	else if (flag == 1)
	{
		if (rotate_mecro(stack->stack_a) == 1)
		{
			stack->command = ft_strjoin_push_swap(stack->command, "ra\n");
			return (1);
		}
		else
			return (0);
	}
	else if (flag == 2)
	{
		rr(stack);
		return (1);
	}
	else
		return (0);
}

int	rb(t_stacks *stack)
{
	int	flag;

	flag = check_command(stack, "rb");
	if (flag == -1)
		exit (write(1, "error", 5));
	if (flag == 0)
		return (1);
	else if (flag == 1)
	{
		if (rotate_mecro(stack->stack_b) == 1)
		{
			stack->command = ft_strjoin_push_swap(stack->command, "rb\n");
			return (1);
		}
		else
			return (0);
	}
	else if (flag == 2)
	{
		rr(stack);
		return (1);
	}
	else
		return (0);
}

int	rr(t_stacks *stack)
{
	int	n;

	n = ft_strlen(stack->command);
	if (stack->command[n - 2] == 'a')
	{
		rotate_mecro(stack->stack_b);
		ft_editstr(stack->command, 3);
		stack->command = ft_strjoin_push_swap(stack->command, "rr\n");
		return (1);
	}
	else if (stack->command[n - 2] == 'b')
	{
		rotate_mecro(stack->stack_a);
		ft_editstr(stack->command, 3);
		stack->command = ft_strjoin_push_swap(stack->command, "rr\n");
		return (1);
	}
	else
		return (0);
}
