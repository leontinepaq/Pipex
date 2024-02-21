/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:43:09 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/02/21 16:43:32 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_tab(void **tab)
{
	unsigned int	i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
	{
		if (!tab[i])
			break ;
		free(tab[i]);
		i++;
	}
	free(tab);
}
