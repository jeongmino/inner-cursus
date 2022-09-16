/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 17:15:15 by junoh             #+#    #+#             */
/*   Updated: 2022/09/16 18:43:07 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

static int sit_philo(t_info *info)
{
    int i;

    i = 0;
        
}

static int  set_fork(t_info *info)
{
    int i;

    i = 0;
    info->forks = malloc(sizeof(pthread_mutex_t) * info->s_args.nums_of_philos);
    if (info->forks)
        return (NULL);
    while (i < info->s_args.nums_of_philos)
    {
        if (pthread_mutex_init(&info->forks[i], NULL) != 0)
            return (FALSE);
    }    
}

int init_table(t_info *info)
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