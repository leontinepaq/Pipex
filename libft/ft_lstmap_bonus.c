/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 20:07:12 by lpaquatt          #+#    #+#             */
/*   Updated: 2023/11/16 16:35:02 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first_new;
	t_list	*new;
	t_list	*prev;

	if (!lst || !f || !del)
		return (NULL);
	first_new = ft_lstnew(f(lst->content));
	if (!first_new)
		return (NULL);
	new = first_new;
	while (lst->next)
	{
		prev = new;
		lst = lst->next;
		new = ft_lstnew(f(lst->content));
		if (!new)
			return (NULL);
		prev->next = new;
	}
	return (first_new);
}
