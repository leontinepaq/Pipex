/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:09:16 by lpaquatt          #+#    #+#             */
/*   Updated: 2023/11/14 13:25:47 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

/*
#include <stdio.h>
#include <ctype.h>

int	main(void)
{
	printf("%d : %d\n", isascii('0'), ft_isascii('0'));
	printf("%d : %d\n", isascii('M'), ft_isascii('M'));
    printf("%d : %d\n", isascii(' '), ft_isascii(' '));
    printf("%d : %d\n", isascii(1), ft_isascii(1));
	printf("%d : %d\n", isascii(127), ft_isascii(127));
	printf("%d : %d\n", isascii('\0' + 128), ft_isascii('\0' + 128));
	printf("%d : %d\n", isascii('\0' + 134), ft_isascii('\0' + 134));
	printf("%d : %d\n", isascii('\0' + 178), ft_isascii('\0' + 178));
	return (0);
}
*/
