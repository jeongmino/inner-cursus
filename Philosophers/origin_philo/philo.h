/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 09:17:24 by junoh             #+#    #+#             */
/*   Updated: 2022/10/03 20:55:36 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <sys/time.h>

/*
INT_MAX
*/
# define VAL_INT_MAX			2147483647

/*
Boolean
*/
# define TRUE  		1
# define FALSE 		0
# define SUCCESS 	0
# define ERROR		1

/*
ERROR MSG
*/
# define ARG1 "There is an error on setting number of philosohpers"
# define ARG2 "There is an error on setting time to die"
# define ARG3 "There is an error on setting time to eat"
# define ARG4 "There is an error on setting time to think"
# define ARG5 "There is an error on setting "

/*
ACTION MSG
*/
# define EATTING "is eating"
# define THINKING "is thinking"
# define SLEEPING "is sleeping"
# define DYING "died"
# define LEFT_FORK "has taken a fork"
# define RIGTH_FORK "has taken a fork"

typedef struct s_args
{
	int	nums_of_philos;
	int	time_to_eat;
	int	time_to_sleep;
	int	time_to_die;
	int	nums_of_must_eat;
}				t_args;

typedef struct s_fork
{
	int		left;
	int		right;
}				t_fork;

typedef struct s_philo
{
	int				id;
	int				eat_cnt;
	size_t			last_eat_t;
	size_t			birth_t;
	pthread_t		thread;
	t_fork			fork;
	struct s_info	*info_ptr;
}					t_philo;

typedef struct s_info
{
	int				philo_dead;
	int				philo_num_full;
	int				full_over;
	int				status;
	int				end;
	int				n_thread;
	size_t			birth_t;
	t_args			s_args;
	t_philo			*philo;
	pthread_mutex_t	*forks;
	pthread_mutex_t	write;
}					t_info;

/*  parse_arg.c */
int			check_args(int argc, char **argv, t_info *info);

/* init_info.c */
int			init_table(t_info *info);

/* timer.c */
long long	get_time(void);
void		smart_timer(size_t time);

/* routine */
void		*routine(void *arg);
int			take_fork(t_philo *philo);
int			eatting(t_philo *philo);
int			thinking_and_sleeping(t_philo *philo);

/* print.c */
int			philo_print(t_info *info, char *status, int i, int eat_status);
void		print_error(int argc, t_info *info);

/* create_philo.c */
int			create_philo(t_info *info);
void		destroy_philos(t_info *info);

/* create_philo.c */
int			create_philo(t_info *info);
void		destroy_philos(t_info *info);

#endif
