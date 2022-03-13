/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 16:48:44 by junoh             #+#    #+#             */
/*   Updated: 2021/12/12 14:19:12 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*node;
	t_list	*ptr;

	ptr = *lst;
	node = *lst;
	while (ptr != NULL)
	{
		ptr = ptr->next;
		ft_lstdelone(node, del);
		node = ptr;
	}
	*lst = NULL;
	return ;
}
