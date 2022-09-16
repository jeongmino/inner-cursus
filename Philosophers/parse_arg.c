/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 12:37:13 by junoh             #+#    #+#             */
/*   Updated: 2022/09/15 12:55:00 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

static int philo_atoi(char *str)
{
    int             i;
    long long       num;

    num = 0;
    i = 0;
    while (str[i] >= '0' && str[i] <= '9')
    {
        num += (str[i] - '0') * 10;
        if (num > VAL_INT_MAX)
            return (FALSE);
        i++;
    }
    
}

int parse_arg(int argc, char *argv, t_info *info)
{
    
}