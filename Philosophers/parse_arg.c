/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 12:37:13 by junoh             #+#    #+#             */
/*   Updated: 2022/09/29 13:10:27 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

static	int	philo_atoi(char *str)
{
	int				i;
	long long		num;

	num = 0;
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + str[i] - '0';
		if (num > VAL_INT_MAX)
			return (FALSE);
		i++;
	}
	return (num);
}

int	static	parse_arg(int argc, char **argv, t_info *info)
{
	info->s_args.nums_of_philos = philo_atoi(argv[1]);
	info->s_args.time_to_die = philo_atoi(argv[2]);
	info->s_args.time_to_eat = philo_atoi(argv[3]);
	info->s_args.time_to_sleep = philo_atoi(argv[4]);
	if (argc == 6)
		info->s_args.nums_of_must_eat = philo_atoi(argv[5]);
	else
		info->s_args.nums_of_must_eat = -1;
	if (!info->s_args.nums_of_philos || !info->s_args.time_to_die || \
		!info->s_args.time_to_eat || !info->s_args.time_to_sleep || \
		(argc == 6 && !info->s_args.nums_of_must_eat))
		return (FALSE);
	return (TRUE);
}

int	check_args(int argc, char **argv, t_info *info)
{
	if (argc < 5 || argc > 6)
	{
		printf("The number of argument is not correct\n");
		return (FALSE);
	}
	else if (parse_arg(argc, argv, info) == FALSE)
	{
		print_error(argc, info);
		return (FALSE);
	}
	return (TRUE);
}
