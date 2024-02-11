/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:06:28 by lpaquatt          #+#    #+#             */
/*   Updated: 2023/11/14 14:43:18 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen((char *)s);
	if (c == '\0')
		return ((char *)s + i);
	while (i >= 0)
	{
		if (s[i] == (unsigned char)c)
			return ((char *)s + i);
		i--;
	}
	return (NULL);
}

/*
#include <stdio.h>
int	main(void)
{
	printf("%p: %p\n",strrchr("abcb",'a'),ft_strrchr("abcb",'a'));
	printf("%s : %s\n",strrchr("abc",'n'),ft_strrchr("abc",'n'));
	printf("%s : %s\n",strrchr("abc",'\0'),ft_strrchr("abc",'\0'));

	printf("%p : %p\n",strrchr("abcb",'b'),ft_strrchr("abcb",'b'));
	printf("%p : %p\n",strrchr("abc",'n'),ft_strrchr("abc",'n'));
	printf("%p : %p\n",strrchr("abc",'\0'),ft_strrchr("abc",'\0'));
	return (0);
}
*/
