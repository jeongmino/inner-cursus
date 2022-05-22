/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 12:14:46 by junoh             #+#    #+#             */
/*   Updated: 2022/05/20 12:27:06 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_num(int a, int b, int c)
{
	ft_putchar(a + 48);
	ft_putchar(b + 48);
	ft_putchar(c + 48);
	if (!((a == 7) && (b == 8) && (c == 9)))
		ft_putchar(',');
	return ;
}

void	ft_print_comb(void)
{
	int	f_d;
	int	s_d;
	int	t_d;

	f_d = 0;
	s_d = 1;
	t_d = 2;
	while (f_d < 8)
	{
		s_d = f_d + 1;
		while (s_d < 9)
		{
			t_d = s_d + 1;
			while (t_d <= 9)
				ft_print_num(f_d, s_d, t_d++);
			s_d++;
		}
		f_d++;
	}
	return ;
}

int	main(void)
{
	ft_print_comb();
	return (0);
}



