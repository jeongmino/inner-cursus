/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 17:22:38 by junoh             #+#    #+#             */
/*   Updated: 2022/06/08 17:50:45 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>

int main(void)
{
    char    *buf = get_next_line(STDIN_FILENO);
//    char    *buf = "asd";
    printf("%s", buf);
    return 0;           
}
