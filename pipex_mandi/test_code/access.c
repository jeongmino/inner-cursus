/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 15:40:36 by junoh             #+#    #+#             */
/*   Updated: 2022/05/07 15:44:40 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	int	mode;

	mode = 0;
	mode |= F_OK;
	if (!access("test.txt", mode))
		printf("File is existing\n");
	else
		printf("File is not existing\n");
	mode &= 0;
	mode |= X_OK;
	if (!access("test.txt", mode))
		printf("File is executable\n");
	else
		printf("File is not executable\n");
	return (0);
}
