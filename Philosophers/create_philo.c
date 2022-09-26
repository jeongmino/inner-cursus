/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 17:08:10 by junoh             #+#    #+#             */
/*   Updated: 2022/09/26 13:31:30 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

int create_philo(t_info *info)
{
    int i;
    t_philo *philo;
    
    pthread_mutex_lock(&info->write);
    i = -1;
    philo = info->philo;
    while (++i < info->s_args.nums_of_philos)
    {
        philo[i].birth_t = get_time();
        info->n_thread = i;
        if (pthread_create(&philo[i].thread, NULL, \
        &routine, (void *) &info) != 0)
        return (FALSE);
        // usleep(1000);
    }
    i = -1;
    while (++i < info->s_args.nums_of_philos)
        if (pthread_join(philo[i].thread, NULL) != 0)
            return (FALSE);
    return (TRUE);
}

void destroy_philos(t_info *info)
{
    int i;

    i = -1;
    while (++i < info->s_args.nums_of_philos)
        pthread_mutex_destroy(&info->forks[i]);
    pthread_mutex_destroy(&info->write);
    free(info->philo);
}