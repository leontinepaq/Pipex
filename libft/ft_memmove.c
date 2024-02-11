/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:25:35 by lpaquatt          #+#    #+#             */
/*   Updated: 2023/11/15 18:10:24 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int			i;

	if (!dest && !src)
		return (NULL);
	i = 0;
	if (dest < src)
	{
		while (i < (int)n)
		{
			((char *)dest)[i] = ((char *)src)[i];
			i++;
		}
	}
	else
	{	
		i = (int)n - 1;
		while (i >= 0)
		{
			((char *)dest)[i] = ((char *)src)[i];
			i--;
		}
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
	char src[3] = "*-";
	char test2[11] = "0123456789";

	printf("%s\n", dest);
	memmove(dest, src, 2);
	printf("%s\n\n", dest);
	
	ft_strcpy(dest, "abcd");
	printf("%s\n", dest);
	ft_memmove(dest, src, 2);
	printf("%s\n\n---\n\n", dest);

	printf("%s\n", test2);
	memmove(test2 + 1, test2, 5);
	printf("%s\n\n", test2);
	
	ft_strcpy(test2, "0123456789");
	
	printf("%s\n", test2);
	ft_memmove(test2 + 1, test2, 5);
	printf("%s", test2);
	
	return (0);
}
*/
