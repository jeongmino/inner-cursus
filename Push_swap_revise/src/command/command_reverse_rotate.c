/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_reverse_rotate.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpark <chpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 19:28:00 by chpark            #+#    #+#             */
/*   Updated: 2022/04/09 17:45:48 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"

int	reverse_rotate_mecro(t_list *s)
{
	int	i;
	int	temp;

	if (s->used_size <= 1)
		return (0);
	i = (s->used_size) - 1;
	temp = s->arr[i];
	while (i > 0)
	{
		s->arr[i] = s->arr[i - 1];
		i--;
	}
	s->arr[0] = temp;
	return (1);
}

int	rra(t_stacks *stack)
{
	int	n;

	n = check_command(stack, "rra");
	if (n == 0)
		return (1);
	else if (n == 1)
	{
		if (reverse_rotate_mecro(stack->stack_a) == 1)
		{
			stack->command = ft_strjoin_push_swap(stack->command, "rra\n");
			return (1);
		}
		else
			return (0);
	}
	else if (n == 2)
	{
		rr(stack);
		return (1);
	}
	else
		return (0);
}

int	rrb(t_stacks *stack)
{
	int	n;

	n = check_command(stack, "rrb");
	if (n == 0)
		return (1);
	else if (n == 1)
	{
		if (reverse_rotate_mecro(stack->stack_b) == 1)
		{
			stack->command = ft_strjoin_push_swap(stack->command, "rrb\n");
			return (1);
		}
		else
			return (0);
	}
	else if (n == 2)
	{
		rr(stack);
		return (1);
	}
	else
		return (0);
}

int	rrr(t_stacks *stack)
{
	int	n;

	n = ft_strlen(stack->command);
	if (stack->command[n - 2] == 'a')
	{
		reverse_rotate_mecro(stack->stack_b);
		ft_editstr(stack->command, 4);
		stack->command = ft_strjoin_push_swap(stack->command, "rrr\n");
		return (1);
	}
	else if (stack->command[n - 2] == 'b')
	{
		reverse_rotate_mecro(stack->stack_a);
		ft_editstr(stack->command, 4);
		stack->command = ft_strjoin_push_swap(stack->command, "rrr\n");
		return (1);
	}
	else
		return (0);
}
