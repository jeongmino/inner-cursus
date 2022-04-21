/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonkim <wonkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:01:49 by chpark            #+#    #+#             */
/*   Updated: 2022/04/21 15:30:03 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"
#include <stdlib.h>

t_stacks	*setup_stack(char **str)
{
	t_stacks	*stacks;
	int			*int_arr;
	int			size;
	int			i;

	size = count_stack_size(str);
	int_arr = (int *)malloc(sizeof(int) * size);
	if (int_arr == NULL)
		exit(ft_put_err(NULL, "Malloc_Error", str, 1));
	i = -1;
	while (str[++i])
		int_arr[i] = ft_atoi_push_swap(str[i], str);
	i = 0;
	int_arr = make_index_sort(int_arr, size, str);
	stacks = (t_stacks *)malloc(sizeof(t_stacks));
	if (stacks == NULL)
		exit(ft_put_err(NULL, "Malloc_Error", str, 1));
	init_stack_a(stacks, int_arr, size, str);
	init_stack_b(stacks, size, str);
	stacks->command = ft_strdup("");
	if (stacks->command == NULL)
		exit(ft_put_err(stacks, "Malloc Error", str, 1));
	return (stacks);
}

int	count_stack_size(char **str)
{
	int	size;

	size = 0;
	while (str[size])
		size++;
	return (size);
}

int	*make_index_sort(int *arr, int size, char **str)
{
	int	*copy_arr;
	int	i;

	copy_arr = (int *)malloc(sizeof(int) * size);
	if (copy_arr == NULL || !check_dup_arr(arr, size))
	{
		free(arr);
		exit(ft_put_err(NULL, "Error", str, 1));
	}
	copy_arr = make_copy_arr(copy_arr, arr, size);
	i = ft_sort_int_arr(copy_arr, size);
	if (!i)
	{
		free(arr);
		free(copy_arr);
		exit(ft_put_err(NULL, NULL, str, 1));
	}
	arr = index_preprocess(copy_arr, arr, size);
	free(copy_arr);
	return (arr);
}

char	**av_to_string(char	**av, int ac)
{
	int		i;
	char	*str;
	char	**result;

	i = 1;
	str = NULL;
	while (i < ac)
	{
		str = ft_strjoin_push_swap(str, av[i++]);
		if (str == NULL)
		{
			free(str);
			break ;
		}
		str = ft_strjoin_push_swap(str, " ");
	}
	result = ft_split(str, " ");
	free(str);
	return (result);
}

int	ft_put_err(t_stacks *stacks, char *message, char **str, int ret)
{
	if (stacks)
	{
		if (stacks->stack_a->arr)
			free(stacks->stack_a->arr);
		if (stacks->stack_a)
			free(stacks->stack_a);
		if (stacks->stack_b->arr)
			free(stacks->stack_b->arr);
		if (stacks->stack_b)
			free(stacks->stack_b);
		if (stacks->command)
			free(stacks->command);
		free(stacks);
	}
	if (str)
		ft_str_free(str);
	if (message != NULL)
		ft_putendl_fd(message, 2);
	return (ret);
}
