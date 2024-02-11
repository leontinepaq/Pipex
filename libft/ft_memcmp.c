/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:26:14 by lpaquatt          #+#    #+#             */
/*   Updated: 2023/11/15 15:04:07 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (i < n && ((unsigned char *)s1)[i] == ((unsigned char *)s2)[i])
		i++;
	if (i == n)
		return (0);
	return ((((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]));
}

/*
#include <stdio.h>

int main(void)
{
	char s[] = {-128, 0, 127, 0};
	char sCpy[] = {-128, 0, 127, 0};
	char s2[] = {0, 0, 127, 0};
	char s3[] = {0, 0, 42, 0};

	printf("%d : %d\n",memcmp(s, sCpy, 4),ft_memcmp(s, sCpy, 4));
	printf("%d : %d\n",memcmp(s, s2, 0),ft_memcmp(s, s2, 0));
	printf("%d : %d\n",memcmp(s, s2, 1),ft_memcmp(s, s2, 1));
	printf("%d : %d\n",memcmp(s2, s, 1),ft_memcmp(s2, s, 1));
	printf("%d : %d\n",memcmp(s2, s3, 6),ft_memcmp(s2, s3, 6));

	return (0);
}
*/

/*

// fonction memcmp retourne -1 ou 1

#include <stdio.h>

int	main(void)
{
	printf("%d : %d\n",memcmp("abc","abc",4),ft_memcmp("abc","abc",4));
	printf("%d : %d\n",memcmp("abc","abn",4),ft_memcmp("abc","abn",4));
	printf("%d : %d\n",memcmp("abcb","abcn",3),ft_memcmp("abcb","abcn",3));
	printf("%d : %d\n",memcmp("abcbbn","abbbn",0),ft_memcmp("abcbbn","abbbn",0));
	printf("%d : %d\n",memcmp("abcbbn","abcbb",14),ft_memcmp("abcbbn","abcbb",14));
	return (0);
}
*/
