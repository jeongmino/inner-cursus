/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 09:17:24 by junoh             #+#    #+#             */
/*   Updated: 2022/09/15 12:48:25 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>

/*
INT_MAX
*/
# define VAL_INT_MAX			2147483647

/*
Boolean
*/
# define TRUE  1
# define FALSE 0

/*
Color
*/
# define RESET "\e[0m"
# define PINK "\e[0;38;5;199m"
# define GREEN "\e[0;32m"
# define BLUE "\e[0;34m"
# define G_BLUE "\e[0;38;5;24m"
# define B_BLUE "\e[1;34m"
# define G_CYAN "\e[0;38;5;44m"


typedef struct s_args
{
    int nums_of_philos;
    int time_to_eat;
    int time_to_sleep;
    int time_to_die;
    int nums_of_must_eat;
}               t_args;

typedef struct s_fork
{
    int     left;
    int     right;
}               t_fork;

typedef struct s_philo
{
    int id;
    int eat_cnt;
    size_t last_eat_t;
    pthread_t   thread;
    t_fork      fork;
}               t_philo;

typedef struct s_info
{
    int     philo_dead;
    t_args  s_args;
    t_philo *phlio;
    pthread_mutex_t	*forks;
	pthread_mutex_t	write;    
}               t_info;

#endif