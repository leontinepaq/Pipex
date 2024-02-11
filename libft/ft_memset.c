/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:32:08 by lpaquatt          #+#    #+#             */
/*   Updated: 2023/11/13 16:48:32 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t		i;
	char		*tmp;

	i = 0;
	tmp = s;
	while (i < n)
	{
		tmp[i] = c;
		i++;
	}
	return (s);
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

int main(void)
{
	char str[4] = "abcd";

	printf("%s\n", str);
	memset(str, 35, 2);
	printf("%s\n\n", str);
	
	ft_strcpy(str, "abcd");
	printf("%s\n", str);
	ft_memset(str, 35, 2);
	printf("%s", str);
	return (0);
}
*/
