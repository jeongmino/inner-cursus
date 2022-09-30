/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 15:56:04 by junoh             #+#    #+#             */
/*   Updated: 2022/09/30 15:32:01 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static int	philo_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while ((str1[i] != '\0' || str2[i] != '\0') && i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

static void	eatting_is_full(t_info *info, int i)
{
	info->philo[i].last_eat_t = get_time();
	if (++(info->philo[i].eat_cnt) == info->s_args.nums_of_must_eat)
		info->philo_num_full++;
	if (info->philo_num_full == info->s_args.nums_of_philos)
		info->full_over++;
	return ;
}

int	philo_print(t_info *info, char *status, int i)
{
	size_t	now_t;

	pthread_mutex_lock(&info->write);
	if (!info->philo_dead && \
			(info->philo[i].eat_cnt != info->s_args.nums_of_must_eat))
	{
		now_t = get_time();
		printf("%s%ld    %d      %s\n", GREEN, \
		now_t - info->birth_t, info->philo[i].id, status);
		if (!philo_strncmp(status, EATTING, ft_strlen(EATTING)))
			eatting_is_full(info, i);
	}
	else
	{
		pthread_mutex_unlock(&info->write);
		return (FALSE);
	}
	pthread_mutex_unlock(&info->write);
	return (TRUE);
}

void	print_error(int argc, t_info *info)
{
	if (!info->s_args.nums_of_philos)
		printf("%s\n", ARG1);
	if (!info->s_args.time_to_die)
		printf("%s\n", ARG2);
	if (!info->s_args.time_to_eat)
		printf("%s\n", ARG3);
	if (!info->s_args.time_to_sleep)
		printf("%s\n", ARG4);
	if (argc == 6 && !info->s_args.nums_of_must_eat)
		printf("%s\n", ARG5);
}
