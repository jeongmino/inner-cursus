/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 09:00:36 by junoh             #+#    #+#             */
/*   Updated: 2022/09/16 18:12:25 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

int main(int argc, char *argv[])
{
    t_info  info;
    t_philo philo;
    
    if (check_args(argc, argv, &info) == FALSE)
        return (1);
    /*
    if (init_table() == FALSE)
        return (1);
    if (create_philo() == FALSE)
        return (1);
    else
        monitoring();
    if (join_threads() == FALSE)
        return (1);
    if (destroy_threads() == FALSE)
        return (1);
    */
    
    
}