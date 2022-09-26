/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 17:15:15 by junoh             #+#    #+#             */
/*   Updated: 2022/09/26 20:06:50 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"
/*
static void fork_print(t_info *info)
{
    int i = 0;

    while (i < info->s_args.nums_of_philos)
    {
        printf("%dth philosopher have left %dth pork\n", info->philo[i].id ,\
        info->philo[i].fork.left);
        printf("%dth philosopher have right %dth pork\n", info->philo[i].id ,\
        info->philo[i].fork.right);
        i++;
    }
    return ;
} */

static int sit_philo(t_info *info)
{
    int i;

    info->philo = malloc(sizeof(t_philo) * info->s_args.nums_of_philos);
    if (info->philo == NULL)
        return (FALSE);
    // memset(info, 0, sizeof(t_info));
    i = -1;
    while (++i < info->s_args.nums_of_philos)
    {
        info->philo[i].id = i + 1;
        info->philo[i].eat_cnt =0;
        info->philo[i].fork.left = i;
        info->philo[i].fork.right = i + 1;
        info->philo[i].s_info_ptr = &info;
    }
    info->philo[0].fork.left = i - 1;
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
    return (TRUE);           
}