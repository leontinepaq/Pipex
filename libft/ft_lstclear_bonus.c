/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 19:36:41 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/02/23 13:21:22 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*prev;

	if (!lst || !(*lst) || !del)
		return ;
	prev = *lst;
	while ((*lst)->next)
	{
		del((*lst)->content);
		prev = *lst;
		*lst = (*lst)->next;
		free (prev);
	}
	ft_lstdelone(*lst, del);
	*lst = NULL;
}
