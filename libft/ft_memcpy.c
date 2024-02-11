/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:02:45 by lpaquatt          #+#    #+#             */
/*   Updated: 2023/11/15 15:18:20 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*tmp;

	if (!dest && !src)
		return (NULL);
	i = 0;
	tmp = dest;
	while (i < n)
	{
		tmp[i] = ((char *)src)[i];
		i++;
	}
	return (dest);
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
	char dest[5] = "abcd";
	char src[3] = "-*";

	printf("%s\n", dest);
	memcpy(dest, src, 2);
	printf("%s\n\n", dest);
	
	ft_strcpy(dest, "abcd");
	printf("%s\n", dest);
	ft_memcpy(dest, src, 2);
	printf("%s", dest);
	return (0);
}
*/
