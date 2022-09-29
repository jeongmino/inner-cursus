/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 17:15:15 by junoh             #+#    #+#             */
/*   Updated: 2022/09/29 16:21:36 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

static	int	sit_philo(t_info *info)
{
	int	i;

	info->philo = malloc(sizeof(t_philo) * info->s_args.nums_of_philos);
	if (info->philo == NULL)
		return (FALSE);
	i = -1;
	while (++i < info->s_args.nums_of_philos)
	{
		info->philo[i].id = i + 1;
		info->philo[i].eat_cnt = 0;
		info->philo[i].mtx_left = &info->forks[i];
		info->philo[i].mtx_right = &info->forks[(i + 1) % info->s_args.nums_of_philos];
		info->philo[i].info_ptr = info;
		info->philo[i].last_eat_t = get_time();
	}
	return (TRUE);
}

static	int	set_fork(t_info *info)
{
	int	i;

	i = -1;
	info->forks = malloc(sizeof(pthread_mutex_t) * info->s_args.nums_of_philos);
	if (info->forks == NULL)
		return (FALSE);
	while (++i < info->s_args.nums_of_philos)
	{
		if (pthread_mutex_init(&info->forks[i], NULL) != 0)
			return (FALSE);
	}
	if (pthread_mutex_init(&info->write, NULL) != 0)
		return (FALSE);
	return (TRUE);
}

int	init_table(t_info *info)
{
	if (set_fork(info) == FALSE)
	{
		printf("Malloc error when setting forks\n");
		return (FALSE);
	}
	if (sit_philo(info) == FALSE)
	{
		printf("Malloc error when sitting philosophers\n");
		return (FALSE);
	}
	return (TRUE);
}
