/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:14:09 by lpaquatt          #+#    #+#             */
/*   Updated: 2023/11/15 15:56:45 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*res;
	int		i;

	if (!s)
		return (NULL);
	res = malloc((ft_strlen((char *)s) + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (s[i])
	{
		res[i] = f(i, s[i]);
		i++;
	}	
	res[i] = '\0';
	return (res);
}

/*
#include <stdio.h>

char	ft_tolower(unsigned int i, char c)
{
	if (i < 0)
		return(0);
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

int	main()
{
	printf("%s",ft_strmapi("ABc ", ft_tolower));
	return (0);
}
*/