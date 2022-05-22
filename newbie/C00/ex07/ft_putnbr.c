/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 13:53:30 by junoh             #+#    #+#             */
/*   Updated: 2022/05/20 14:35:14 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_numlen(int nb)
{
	int len;

	len = 0;
	if (nb < 0)
		nb = nb * -1;
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

int	ft_pow(int n)
{
	int	ret;

	ret = 1;
	while (n > 0)
	{
		ret = ret * 10;
		n--;
	}
	return (ret);
}
void	ft_putnbr(int nb)
{
	int	nbr_len;
	int	nb_c;

	nbr_len = ft_numlen(nb) - 1;
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = nb * -1;
	}
	while (nbr_len > 0)
	{
		nb_c = nb / ft_pow(nbr_len);
		nb = nb - (nb_c * ft_pow(nbr_len--));
		ft_putchar(nb_c + 48);
	}
	ft_putchar(nb % 10 + 48);
	return ;
}

int	main(void)
{
	ft_putnbr(422);
	ft_putnbr(2147483647);
	return (0);
}

