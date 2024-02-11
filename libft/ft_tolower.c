/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:07:58 by lpaquatt          #+#    #+#             */
/*   Updated: 2023/11/13 16:50:56 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

/*
#include <stdio.h>
#include <ctype.h>

int	main(void)
{
	printf("%c : %c\n", tolower('m'), ft_tolower('m'));
	printf("%c : %c\n", tolower('M'), ft_tolower('M'));
    printf("%d : %d\n", tolower(' '), ft_tolower(' '));
    printf("%d : %d\n", tolower(1), ft_tolower(1));
	return (0);
}
*/
