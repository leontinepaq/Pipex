/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:17:08 by lpaquatt          #+#    #+#             */
/*   Updated: 2023/11/13 18:30:31 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return ((void *)s + i);
		i++;
	}
	return (NULL);
}

/*
#include <stdio.h>
int	main(void)
{

	char s[] = {0, 1, 2 ,3 ,4 ,5};

	printf("%p : %p\n",memchr("abcbb",'b',4),ft_memchr("abcbb",'b',4));
	printf("%p : %p\n",memchr("abcbbn",'n',4),ft_memchr("abcbbn",'n',4));
	printf("%p : %p\n",memchr("abcbb",'\0',4),ft_memchr("abcbb",'\0',4));
	printf("%p : %p\n",memchr(s, 2 + 2*256, 3),ft_memchr(s, 2 + 256, 3));
	printf("%p : %p\n",memchr(s, 2, 3),ft_memchr(s, 2, 3));
	return (0);
}
*/
