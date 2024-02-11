/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:09:16 by lpaquatt          #+#    #+#             */
/*   Updated: 2023/11/13 16:47:36 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

/*
#include <stdio.h>
#include <ctype.h>

int	main(void)
{
	printf("%d : %d\n", isdigit('0'), ft_isdigit('0'));
	printf("%d : %d\n", isdigit('M'), ft_isdigit('M'));
    printf("%d : %d\n", isdigit(' '), ft_isdigit(' '));
    printf("%d : %d\n", isdigit(1), ft_isdigit(1));
	return (0);
}
*/
