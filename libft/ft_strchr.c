/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:41:17 by lpaquatt          #+#    #+#             */
/*   Updated: 2023/11/15 12:59:59 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
			return ((char *)s + i);
		i++;
	}
	if (c == '\0')
		return ((char *)s + i);
	return (NULL);
}

/*
#include <stdio.h>
int	main(void)
{
	printf("%s : %s\n",strchr("abcb",'b'),ft_strchr("abcb",'b'));
	printf("%s : %s\n",strchr("abc",'n'),ft_strchr("abc",'n'));
	printf("%s : %s\n",strchr("abc",'\0'),ft_strchr("abc",'\0'));

	printf("%p : %p\n",strchr("abcb",'b'),ft_strchr("abcb",'b'));
	printf("%p : %p\n",strchr("abc",'n'),ft_strchr("abc",'n'));
	printf("%p : %p\n",strchr("abc",'\0'),ft_strchr("abc",'\0'));
	printf("%p : %p\n",strchr("tr,'t' + 256),ft_strchr("tr",'t' + 256));
	return (0);
}
*/
