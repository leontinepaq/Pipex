/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:14:09 by lpaquatt          #+#    #+#             */
/*   Updated: 2023/11/15 13:19:03 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i] && i + 1 < n)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/*
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int	main(void)
{
	char	*a;
	char	*b;
	unsigned int	n;

	a = "test\200";
	b = "test\3";
	n = 6;

	printf("Mm resultat que strncmp? %d\n", strncmp(a,b,n)==ft_strncmp(a,b,n));
	printf("%d : %d", strncmp(a,b,n), ft_strncmp(a,b,n));
	return(0);
}
*/
