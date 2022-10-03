/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 17:08:10 by junoh             #+#    #+#             */
/*   Updated: 2022/10/03 21:27:58 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

int	create_philo(t_info *info)
{
	int		i;
	t_philo	*philo;

	pthread_mutex_lock(&info->write);
	i = -1;
	philo = info->philo;
	while (++i < info->s_args.nums_of_philos)
	{
		info->n_thread = i;
		if (pthread_create(&philo[i].thread, NULL, \
		&routine, &info->philo[i]) != 0)
			return (FALSE);
		// if (pthread_detach(philo[i].thread) != 0)
		// 	return (FALSE);
	}
	info->birth_t = get_time();
	pthread_mutex_unlock(&info->write);
	return (TRUE);
}

void	destroy_philos(t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->s_args.nums_of_philos)
		pthread_mutex_destroy(&info->forks[i]);
	pthread_mutex_destroy(&info->write);
	free(info->philo);
	free(info->forks);
}
