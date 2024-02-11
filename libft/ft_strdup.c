/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:40:09 by lpaquatt          #+#    #+#             */
/*   Updated: 2023/11/13 16:49:32 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dest;
	int		len;
	int		i;

	len = 0;
	while (src[len] != '\0')
		len++;
	dest = malloc((len +1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (i <= len)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

/*
#include <unistd.h>
#include <string.h>
#include <stdio.h>

int	main(void)
{
	char	*str1 = "test1";
	char	*str2 = "";
	char	*str3 = "a\0b";
	
	printf("strdup : %s\nft_strdup : %s\n\n",strdup(str1),ft_strdup(str1));
	printf("strdup : %s\nft_strdup : %s\n\n",strdup(str2),ft_strdup(str2));
	printf("strdup : %s\nft_strdup : %s\n",strdup(str3),ft_strdup(str3));
	return (0);
}
*/
