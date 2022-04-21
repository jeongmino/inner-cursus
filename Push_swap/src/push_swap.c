/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:01:26 by chpark            #+#    #+#             */
/*   Updated: 2022/04/21 15:03:37 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"
#include <unistd.h>

int	main(int ac, char **av)
{
	int			len;
	t_stacks	*stacks;
	char		**str;

	if (ac == 1)
		return (0);
	str = av_to_string(av, ac);
	if (!str)
		return (0);
	if (count_stack_size(str) <= 1)
		exit(ft_put_err(NULL, NULL, NULL, 1));
	stacks = setup_stack(str);
	if (ft_sort(stacks, count_stack_size(str)) == -1)
		exit(ft_put_err(NULL, "Malloc_Error", str, 1));
	len = 0;
	while (str[len])
		free(str[len++]);
	free(str[len]);
	free(str);
	len = ft_strlen(stacks->command);
	write(1, stacks->command, len);
	return (ft_put_err(stacks, NULL, NULL, 0));
}

void	init_stack_a(t_stacks *stacks, int *src_arr, int size, char **str)
{
	int	i;

	stacks->stack_a = (t_list *)malloc(sizeof(t_list));
	if (!stacks->stack_a)
	{
		free(src_arr);
		exit(ft_put_err(stacks, "Malloc Error", str, 1));
	}
	stacks->stack_a->arr = (int *)malloc(sizeof(int) * size);
	if (!stacks->stack_a->arr)
	{
		free(src_arr);
		exit(ft_put_err(stacks, "Malloc Error", str, 1));
	}
	i = 0;
	while (i < size)
	{
		stacks->stack_a->arr[i] = src_arr[i];
		i++;
	}
	stacks->stack_a->used_size = size;
	free(src_arr);
	return ;
}

void	init_stack_b(t_stacks *stacks, int size, char **str)
{
	int	i;

	stacks->stack_b = (t_list *)malloc(sizeof(t_list));
	if (!stacks->stack_b)
		exit(ft_put_err(stacks, "Malloc Error", str, 1));
	stacks->stack_b->arr = (int *)malloc(sizeof(int) * size);
	if (!stacks->stack_b->arr)
		exit(ft_put_err(stacks, "Malloc Error", str, 1));
	i = -1;
	while (++i < size)
		stacks->stack_b->arr[i] = -1;
	stacks->stack_b->used_size = 0;
	return ;
}
