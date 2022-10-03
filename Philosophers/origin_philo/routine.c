/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 12:31:23 by junoh             #+#    #+#             */
/*   Updated: 2022/10/03 21:03:24 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	pthread_mutex_lock(&philo->info_ptr->write);
	philo->last_eat_t = get_time();
	pthread_mutex_unlock(&philo->info_ptr->write);
	if (philo->id % 2 == 0)
		smart_timer(philo->info_ptr->s_args.time_to_eat / 2);
	while (take_fork(philo) && eatting(philo) && thinking_and_sleeping(philo))
		;
	return ((void *)TRUE);
}

int	take_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->info_ptr->forks[philo->fork.left]);
	if (philo_print(philo->info_ptr, LEFT_FORK, philo->id - 1, 0) == ERROR)
	{
		pthread_mutex_unlock(&philo->info_ptr->forks[philo->fork.left]);
		return (FALSE);
	}
	pthread_mutex_lock(&philo->info_ptr->forks[philo->fork.right]);
	if (philo_print(philo->info_ptr, RIGTH_FORK, philo->id - 1, 0) == ERROR)
	{
		pthread_mutex_unlock(&philo->info_ptr->forks[philo->fork.right]);
		pthread_mutex_unlock(&philo->info_ptr->forks[philo->fork.left]);
		return (FALSE);
	}
	return (TRUE);
}

int	eatting(t_philo *philo)
{
	if (philo_print(philo->info_ptr, EATTING, philo->id - 1, 1) == ERROR)
		return (FALSE);
	smart_timer(philo->info_ptr->s_args.time_to_eat);
	return (TRUE);
}

int	thinking_and_sleeping(t_philo *philo)
{
	if (philo_print(philo->info_ptr, SLEEPING, philo->id - 1, 0) == ERROR)
		return (FALSE);
	pthread_mutex_unlock(&philo->info_ptr->forks[philo->fork.left]);
	pthread_mutex_unlock(&philo->info_ptr->forks[philo->fork.right]);
	smart_timer(philo->info_ptr->s_args.time_to_sleep);
	if (philo_print(philo->info_ptr, THINKING, philo->id - 1, 0) == ERROR)
		return (FALSE);
	usleep(50);
	return (TRUE);
}
