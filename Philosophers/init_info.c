/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 17:15:15 by junoh             #+#    #+#             */
/*   Updated: 2022/09/27 10:43:53 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

void fork_print(t_info *info)
{
    int i = 0;

    while (i < info->s_args.nums_of_philos)
    {
        printf("%dth philosopher have %dth id\n", info->philo[i].id, info->philo[i].id);
        printf("%dth philosopher have eat_cnt = %d\n", info->philo[i].id, info->philo[i].eat_cnt);
        printf("%dth philosopher have left %dth pork\n", info->philo[i].id ,\
        info->philo[i].fork.left);
        printf("%dth philosopher have right %dth pork\n", info->philo[i].id ,\
        info->philo[i].fork.right);
        i++;
    }
    return ;
}

static int sit_philo(t_info *info)
{
    int i;

    info->philo = malloc(sizeof(t_philo) * info->s_args.nums_of_philos);
    if (info->philo == NULL)
        return (FALSE);
    i = -1;
    while (++i < info->s_args.nums_of_philos)
    {
        info->philo[i].id = i + 1;
        info->philo[i].eat_cnt =0;
        info->philo[i].fork.left = i;
        info->philo[i].fork.right = i + 1;
        info->philo[i].info_ptr = info;
    }
    info->philo[0].fork.left = i;
    return (TRUE);   
}

static int  set_fork(t_info *info)
{
    int i;
    // t_philo *philo_ptr;
    
    i = -1;
    // philo_ptr = info->philo;
    info->forks = malloc(sizeof(pthread_mutex_t) * info->s_args.nums_of_philos);
    if (info->forks == NULL)
        return (FALSE);
    while (++i < info->s_args.nums_of_philos)
    {
        // philo_ptr[i].fork = malloc(sizeof(pthread_mutex_t) * info->s_args.nums_of_philos);       
        if (pthread_mutex_init(&info->forks[i], NULL) != 0)
            return (FALSE);
    }
    if (pthread_mutex_init(&info->write, NULL) != 0)
        return (FALSE);
    return (TRUE);    
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
    // fork_print(info);
    return (TRUE);           
}