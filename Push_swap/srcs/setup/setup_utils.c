/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimwon <kimwon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 16:20:28 by kimwon            #+#    #+#             */
/*   Updated: 2022/04/09 17:46:33 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"
#include <stdlib.h>
#include <stdio.h>

char	*ft_strjoin_push_swap(char *left_line, char *buff)
{
	size_t	ll;
	size_t	bl;
	char	*tmp;

	if (left_line == NULL)
		left_line = ft_strdup("");
	if (!buff || !*buff)
		return (0);
	ll = ft_strlen(left_line);
	bl = ft_strlen(buff);
	tmp = (char *)malloc(sizeof(char) * (ll + bl + 1));
	if (!tmp)
		return (NULL);
	ft_strlcpy(tmp, left_line, ll + 1);
	ft_strlcpy(tmp + ll, buff, bl + 1);
	free(left_line);
	return (tmp);
}

int	ft_atoi_push_swap(const char *nptr, char **str)
{
	long long	sign;
	long long	result;

	sign = 1;
	result = 0;
	if ((*nptr >= 9 && 13 >= *nptr) || *nptr == 32)
		exit(ft_put_err(NULL, "Error", str, 1));
	if (*nptr == '-')
		sign = -1;
	if (*nptr == '-' || *nptr == '+')
		nptr++;
	if (*nptr == '\0')
		exit(ft_put_err(NULL, "Error", str, 1));
	while (*nptr >= '0' && '9' >= *nptr)
		result = result * 10 + sign * (*nptr++ - '0');
	if (result > 2147483647 || result < -2147483648)
		exit(ft_put_err(NULL, "Error", str, 1));
	if (*nptr != '\0' && !(*nptr >= '0' && '9' >= *nptr))
		exit(ft_put_err(NULL, "Error", str, 1));
	return (result);
}

int	ft_sort_int_arr(int *tab, int size)
{
	int	index;
	int	sub;
	int	tmp;
	int	change_cnt;

	change_cnt = 0;
	index = 0;
	while (index < size - 1)
	{
		sub = index + 1;
		while (sub < size)
		{
			if (tab[index] > tab[sub])
			{
				tmp = tab[index];
				tab[index] = tab[sub];
				tab[sub] = tmp;
				change_cnt++;
			}
			sub++;
		}
		index++;
	}
	return (change_cnt);
}

int	*index_preprocess(int *sorted, int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (arr[i] == sorted[j])
			{
				arr[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
	return (arr);
}

int	check_dup_arr(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] == arr[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
