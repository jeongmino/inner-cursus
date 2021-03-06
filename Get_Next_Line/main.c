/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 17:22:38 by junoh             #+#    #+#             */
/*   Updated: 2022/06/28 16:43:27 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>

int main(int ac, char **av)
{
    int fd;
    char    *line;
    
    fd = open(av[1], O_RDONLY);
    while (1)
    {
        line = get_next_line(fd);
        if (line == NULL)
            break;
        printf("%s", line);
    }
    return (0);           
}
