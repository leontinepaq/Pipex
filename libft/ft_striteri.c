/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:32:05 by lpaquatt          #+#    #+#             */
/*   Updated: 2023/11/15 16:00:31 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		(*f)(i, &s[i]);
		i++;
	}
}

/*
#include <stdio.h>

void	ft_tolower(unsigned int i, char *s)
{
	char	c;
	
	if (i < 0)
		return;
	c = *s;
	if (c >= 'A' && c <= 'Z')
		*s = c + 32;
	return;
}

int	main()
{
	char s[4] = "ABc";

	printf("s : %s\n", s);
	ft_striteri(s, ft_tolower);
	printf("lower : %s", s);
	
	return (0);
}
*/
