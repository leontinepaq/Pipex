/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:47:07 by lpaquatt          #+#    #+#             */
/*   Updated: 2023/11/15 15:28:40 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*res;
	size_t		i;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		len = 0;
	else if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	res = malloc((len + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (i < len && s[i + start] != '\0')
	{
		res[i] = s[i + start];
		i++;
	}
	res[i] = '\0';
	return (res);
}

/*
#include <unistd.h>
#include <string.h>
#include <stdio.h>

int	main(void)
{
	printf("test1 : %s\n", ft_substr("test1", 0, 5));
	printf("1 : %s\n", ft_substr("test1", 4, 5));
	printf("s : %s\n", ft_substr("test1", 2, 1));
	printf(" : %s\n", ft_substr("", 0, 1));
	printf("a : %s\n", ft_substr("a\0b", 0, 3));
	return (0);
}
*/
