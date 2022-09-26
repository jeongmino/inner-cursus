/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 12:31:23 by junoh             #+#    #+#             */
/*   Updated: 2022/09/26 20:09:36 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

void    *routine(void *argument)
{
    t_info *info;
    int     i;

    info = (t_info *)argument;
    pthread_mutex_lock(&info->write);
    printf("i = %d\n", i);
    i = info->n_thread;
    printf("debug2\n");
    info->philo[i].last_eat_t = get_time();
    printf("debug3\n");
    pthread_mutex_unlock(&info->write);
    printf("debug4\n");
    if (info->philo[i].id / 2 == 0)
        smart_timer(info->s_args.time_to_eat / 2);
    printf("debug5\n");
    while(take_fork(info) && eatting(info) && thinking_and_sleeping(info))
            ;
    return ((void *)TRUE);
}

int take_fork(t_info *info)
{
    int i;

    i = info->n_thread;
    pthread_mutex_lock(&info->forks[info->philo[i].fork.left]);        
    if (philo_print(info, LEFT_FORK, i) == FALSE)
        return (FALSE);
    pthread_mutex_lock(&info->forks[info->philo[i].fork.right]); 
    if (philo_print(info, RIGTH_FORK, i))
        return (FALSE);
    pthread_mutex_unlock(&info->forks[info->philo[i].fork.left]); 
    pthread_mutex_unlock(&info->forks[info->philo[i].fork.right]); 
    return (TRUE);
}

int eatting(t_info *info)
{
    int i;

    i = info->n_thread;
    if (philo_print(info, EATTING, i) == FALSE)
        return (FALSE);
    smart_timer(info->s_args.time_to_eat);
    return (TRUE);
}

int thinking_and_sleeping(t_info *info)
{
    int i;

    i = info->n_thread;
    if (philo_print(info, SLEEPING, i) == FALSE)
        return (FALSE);
    smart_timer(info->s_args.time_to_sleep);
    if (philo_print(info, THINKING, i) == FALSE)
        return (FALSE);
    usleep(50);
    return (TRUE);
}
