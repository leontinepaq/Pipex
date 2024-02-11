/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:33:07 by lpaquatt          #+#    #+#             */
/*   Updated: 2023/11/13 16:51:00 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c -32);
	return (c);
}

/*
#include <stdio.h>
#include <ctype.h>

int	main(void)
{
	printf("%c : %c\n", toupper('m'), ft_toupper('m'));
	printf("%c : %c\n", toupper('M'), ft_toupper('M'));
    printf("%d : %d\n", toupper(' '), ft_toupper(' '));
    printf("%d : %d\n", toupper(1), ft_toupper(1));
	return (0);
}
*/
