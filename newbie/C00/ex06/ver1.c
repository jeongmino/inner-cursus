/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 12:28:19 by junoh             #+#    #+#             */
/*   Updated: 2022/05/20 13:28:55 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

char	*ft_make_arr(void)
{
	char	result_arr[6];
	char	*result_ptr;

	result_ptr = result_arr;
	result_arr[0] = '0';
	result_arr[1] = '0';
	result_arr[2] = ' ';
	result_arr[3] = '0';
	result_arr[4] = '0';
	result_arr[5] = ',';
	return (result_ptr);
}

void	ft_putarr(char arr[], int flag)
{
	int	i;

	i = 0;
	while (i < 5)
		ft_putchar(arr[i++]);
	if (flag == 1)
		ft_putchar(arr[i]);
	return ;
}
void	ft_print_comb2(void)
{
	char	*arr;
	int		i;
	int		j;

	i = 0;
	j = 1;
	arr = ft_make_arr();
	while (i < 99)
	{
		j = i + 1;
		arr[0] = i / 10 + '0';
		arr[1] = i % 10 + '0';
		while (j < 100)
		{
			arr[3] = (j / 10 + 48);
			arr[4] = (j % 10 + 48);
			if (!(i == 98 && j == 99))
				ft_putarr(arr, 1);
			else
				ft_putarr(arr, 0);
			j++;
		}
		i++;
	}
}

int	main(void)
{
	ft_print_comb2();
	return (0);
}
