/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 15:56:04 by junoh             #+#    #+#             */
/*   Updated: 2022/09/16 17:14:16 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

void    print_error(int argc, t_info *info)
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