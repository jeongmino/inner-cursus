/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 09:00:36 by junoh             #+#    #+#             */
/*   Updated: 2022/10/03 21:36:46 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

static void	dying_msg(t_info *info, size_t now_t, int i)
{
	printf("%ld %d %s\n", \
	now_t - info->birth_t, info->philo[i].id, DYING);
}

static int	one_philo(t_info *info)
{
	size_t	now_t;

	if (pthread_mutex_init(&info->write, NULL) != 0)
		return (FALSE);
	info->birth_t = get_time();
	now_t = get_time();
	printf("%ld %d %s\n", \
		now_t - info->birth_t, info->philo[0].id, LEFT_FORK);
	smart_timer(info->s_args.time_to_die);
	dying_msg(info, get_time(), 0);
	destroy_philos(info);
	return (TRUE);
}

static	void	monitoring(t_info *info)
{
	int		i;
	int		end_f;
	size_t	now_t;

	while (1)
	{
		i = -1;
		while (++i < info->s_args.nums_of_philos)
		{
			pthread_mutex_lock(&info->write);
			end_f = info->end;
			now_t = get_time();
			if (now_t > info->s_args.time_to_die + info->philo[i].last_eat_t)
			{
				info->end++;
				printf("%ld %d died\n", now_t - info->birth_t, i + 1);
				pthread_mutex_unlock(&info->write);
				return ;
			}
			else
				pthread_mutex_unlock(&info->write);
			if (end_f)
				return ;
		}
	}
}

int	main(int argc, char *argv[])
{
	t_info	info;
	int		i;

	memset(&info, 0, sizeof(t_info));
	if (check_args(argc, argv, &info) == FALSE)
		return (1);
	if (init_table(&info) == FALSE)
		return (1);
	if (info.s_args.nums_of_philos == 1)
	{
		if (one_philo(&info) == FALSE)
			return (1);
		return (0);
	}
	if (create_philo(&info) == FALSE)
		return (1);
	monitoring(&info);
	i = -1;
	while (++i < info.s_args.nums_of_philos)
	{
		if (pthread_join(info.philo[i].thread, NULL) != 0)
			return (FALSE);
	}
	destroy_philos(&info);
	return (0);
}
