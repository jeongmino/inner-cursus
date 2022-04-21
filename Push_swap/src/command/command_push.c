/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpark <chpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 19:16:59 by chpark            #+#    #+#             */
/*   Updated: 2022/04/09 17:44:06 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"

static int	push_mecro(t_list *a, t_list *b)
{
	int	i;
	int	temp;

	if (a->arr[0] == -1 || a->used_size < 1)
		return (0);
	if (b->used_size <= 1)
		i = 0;
	else
		i = (b->used_size) - 1;
	temp = b->arr[i];
	b->used_size += 1;
	reverse_rotate_mecro(b);
	b->arr[0] = a->arr[0];
	if (i < b->used_size)
		b->arr[i + 1] = temp;
	rotate_mecro(a);
	i = a->used_size - 1;
	a->arr[i] = -1;
	a->used_size -= 1;
	return (1);
}

int	pa(t_stacks *stack)
{
	int	flag;

	flag = check_command(stack, "pa");
	if (flag == 0)
	{
		push_mecro(stack->stack_b, stack->stack_a);
		ft_editstr(stack->command, 3);
		return (1);
	}
	else if (flag == 1)
	{
		push_mecro(stack->stack_b, stack->stack_a);
		stack->command = ft_strjoin_push_swap(stack->command, "pa\n");
		return (1);
	}
	else
		return (0);
}

int	pb(t_stacks *stack)
{
	int	flag;

	flag = check_command(stack, "pb");
	if (flag == 0)
	{
		push_mecro(stack->stack_a, stack->stack_b);
		ft_editstr(stack->command, 3);
		return (1);
	}
	else if (flag == 1)
	{
		push_mecro(stack->stack_a, stack->stack_b);
		stack->command = ft_strjoin_push_swap(stack->command, "pb\n");
		return (1);
	}
	else
		return (0);
}
