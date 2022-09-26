/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 09:00:36 by junoh             #+#    #+#             */
/*   Updated: 2022/09/26 13:48:06 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"


static void dying_msg(t_info *info, size_t now_t, int i)
{
     info->philo_dead++;
     printf("%s%ld      %d    %s", PINK, \
    now_t - info->philo[i].birth_t, info->philo[i].id, DYING);
    pthread_mutex_unlock(&info->write);
}

static void monitoring(t_info *info)
{
    int     i;
    size_t  now_t;
    
    while (1)
    {
        i = -1;
        while (++i < info->s_args.nums_of_philos)
        {
            pthread_mutex_lock(&info->write);
            now_t = get_time();
            if (now_t > info->s_args.time_to_die + info->philo[i].last_eat_t)
            {
                dying_msg(info, now_t, i);
                return ;                    
            }
            else if (info->full_over != 0)
            {
                pthread_mutex_unlock(&info->write);
                return ;
            }
            pthread_mutex_unlock(&info->write);
        }
    }
}

int main(int argc, char *argv[])
{
    t_info  info;
    
    memset(&info, 0, sizeof(t_info));
    if (check_args(argc, argv, &info) == FALSE)
        return (1);
    if (init_table(&info) == FALSE)
        return (1);

    if (create_philo(&info) == FALSE)
        return (1);
    else
        monitoring(&info);
    destroy_philos(&info);
    return (0);
    
}