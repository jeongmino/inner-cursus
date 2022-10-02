/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 15:56:04 by junoh             #+#    #+#             */
/*   Updated: 2022/10/02 22:25:34 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

// static int	philo_strncmp(const char *s1, const char *s2, size_t n)
// {
// 	size_t			i;
// 	unsigned char	*str1;
// 	unsigned char	*str2;

// 	str1 = (unsigned char *)s1;
// 	str2 = (unsigned char *)s2;
// 	i = 0;
// 	while ((str1[i] != '\0' || str2[i] != '\0') && i < n)
// 	{
// 		if (str1[i] != str2[i])
// 			return (str1[i] - str2[i]);
// 		i++;
// 	}
// 	return (0);
// }

// static void	eatting_is_full(t_info *info, int i)
// {
// 	info->philo[i].last_eat_t = get_time();
// 	if (++(info->philo[i].eat_cnt) == info->s_args.nums_of_must_eat)
// 		info->philo_num_full++;
// 	if (info->philo_num_full == info->s_args.nums_of_philos)
// 		info->full_over++;
// 	return ;
// }

int	philo_print(t_info *info, char *str, int i, int eat_status)
{
	size_t	now_t;

	pthread_mutex_lock(&info->write);
	if (info->end == 0)
	{
		now_t = get_time();
		printf("%ld %d %s\n", now_t - info->birth_t, i + 1, str); // 차후 수정
		if (eat_status)
		{
			info->philo[i].last_eat_t = now_t;
			if (++(info->philo[i].eat_cnt) == info->s_args.nums_of_must_eat)
			{
				info->philo_num_full++;
				if (info->philo_num_full == info->s_args.nums_of_philos)
					info->end++;
			}
		}
	}
	else
	{
		pthread_mutex_unlock(&info->write);
		return (ERROR);
	}
		pthread_mutex_unlock(&info->write);
	return (SUCCESS);
}

void	print_error(int argc, t_info *info)
{
	if (!info->s_args.nums_of_philos)
		printf("%s\n", ARG1);
	if (!info->s_args.time_to_die)
		printf("%s\n", ARG2);
	if (!info->s_args.time_to_eat)
		printf("%s\n", ARG3);
	if (!info->s_args.time_to_sleep)
		printf("%s\n", ARG4);
	if (argc == 6 && !info->s_args.nums_of_must_eat)
		printf("%s\n", ARG5);
}
