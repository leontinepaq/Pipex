/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:48:43 by lpaquatt          #+#    #+#             */
/*   Updated: 2023/11/13 16:59:17 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t		i;
	char		*tmp;

	i = 0;
	tmp = s;
	while (i < n)
	{
		tmp[i] = '\0';
		i++;
	}
}

/*
#include <stdio.h> 

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	main(void)
{
	char str[4] = "abcd";

	printf("1: %s\n", str);
	bzero(str, 2);
	printf("2: %s\n", str);
	printf("3: %s\n\n", str + 2);
	
	ft_strcpy(str, "abcd");
	printf("1: %s\n", str);
	ft_bzero(str, 2);
	printf("2: %s\n", str);
	printf("3: %s", str + 2);
	return (0);
}
*/
