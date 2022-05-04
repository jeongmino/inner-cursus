/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_check_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpark <chpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 20:18:26 by chpark            #+#    #+#             */
/*   Updated: 2022/05/04 16:43:13 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"

int	check_command_s(t_stacks *stack, char *command, int n)
{
	if (command[1] == 'a')
	{
		if (stack->command[n - 3] == 's')
		{
			if (stack->command[n - 2] == 'a' || stack->command[n - 2] == 's')
				return (0);
			else
				return (2);
		}
	}
	if (command[1] == 'b')
	{
		if (stack->command[n - 3] == 's')
		{
			if (stack->command[n - 2] == 'b' || stack->command[n - 2] == 's')
				return (0);
			else
				return (2);
		}
	}
	return (1);
}

int	check_command_p(t_stacks *stack, char *command, int n)
{
	if (stack->command[n - 3] == 'p' && stack->command[n - 2] != command[1])
		return (0);
	else
		return (1);
}

int	check_command_ra(t_stacks *stack, int n)
{
	if ((stack->command[n - 3] == 'r') && (stack->command[n - 2] == 'b'))
		return (2);
	else
		return (1);
}

int	check_command_rb(t_stacks *stack, int n)
{
	if ((stack->command[n - 3] == 'r') && (stack->command[n - 2] == 'a'))
		return (2);
	else
		return (1);
}

int	check_command_rr(t_stacks *stack, char *command, int n)
{
	if ((stack->command[n - 4] == 'r') && (stack->command[n - 3] == 'r') \
		&& (stack->command[n - 2] != command[2]))
		return (2);
	else
		return (1);
}
