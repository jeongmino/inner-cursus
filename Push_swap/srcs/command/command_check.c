/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpark <chpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 20:18:26 by chpark            #+#    #+#             */
/*   Updated: 2022/04/06 18:57:05 by chpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"

int	check_command(t_stacks *stack, char *command)
{
	int	n;

	n = ft_strlen(stack->command);
	if (n == 0)
		return (1);
	else if (command[0] == 's')
		return (check_command_s(stack, command, n));
	else if (command[0] == 'p')
		return (check_command_p(stack, command, n));
	else if (command[0] == 'r')
	{
		if (command[2] == '\0' && command[1] == 'a')
			return (check_command_ra(stack, n));
		else if (command[2] == '\0' && command[1] == 'b')
			return (check_command_rb(stack, n));
		else
			return (check_command_rr(stack, command, n));
	}
	else
		return (-1);
}
