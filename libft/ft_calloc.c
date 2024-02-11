/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:11:24 by lpaquatt          #+#    #+#             */
/*   Updated: 2023/11/16 14:39:50 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void				*res;
	size_t				i;

	if (size == 0 || nmemb == 0)
	{
		res = malloc(0);
		return (res);
	}
	if (nmemb > (size_t)(-1) / size)
		return (NULL);
	res = malloc(nmemb * size);
	if (res == NULL)
		return (NULL);
	i = 0;
	while (i < nmemb * size)
	{
		((unsigned char *)res)[i] = '\0';
		i++;
	}
	return (res);
}

/*
#include <limits.h>
#include <stdio.h>

int main(void)
{
	void * p = ft_calloc(2, 2);
	char e[] = {0, 0, 0, 0};
	
	printf("%d\n",ft_calloc(INT_MAX, INT_MAX) == NULL);
		
	return (0);
}
*/
