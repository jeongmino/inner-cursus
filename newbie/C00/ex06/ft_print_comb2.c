/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 13:30:01 by junoh             #+#    #+#             */
/*   Updated: 2022/05/20 13:42:30 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_put_num(int i, int j, int flag)
{
	ft_putchar(i / 10 + '0');
	ft_putchar(i % 10 + '0');
	ft_putchar(' ');
	ft_putchar(j / 10 + '0');
	ft_putchar(j % 10 + '0');
	if (flag == 1)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
	return ;
}

void	ft_print_comb2(void)
{
	int	i;
	int	j;

	i = 0;
	while (i < 99)
	{
		j = i + 1;
		while (j < 100)
		{
			if (!(i == 98 && j == 99))
				ft_put_num(i, j, 1);
			else
				ft_put_num(i, j ,0);
			j++;
		}
		i++;
	}
	return ;
}

int	main(void)
{
	ft_print_comb2();
	return (0);
}



