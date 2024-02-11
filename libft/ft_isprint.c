/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:04:42 by lpaquatt          #+#    #+#             */
/*   Updated: 2023/11/13 16:47:39 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= ' ' && c <= 126)
		return (16384);
	return (0);
}

/*
#include <stdio.h>
#include <ctype.h>

int	main(void)
{
    int c = '\0';

    while (c <= '\0' + 200)
    {
        if (isprint(c) != ft_isprint(c))
        {
            printf("problem : %d, %d, %d\n", c, isprint(c), ft_isprint(c));
        }
        c += 1;
    }
	return (0);
}
*/