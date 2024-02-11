/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 09:56:01 by lpaquatt          #+#    #+#             */
/*   Updated: 2023/11/13 16:47:07 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	res;
	int	i;
	int	signe;

	i = 0;
	signe = 1;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
	{
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe = -signe;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{	
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (signe * res);
}

/*
#include <stdio.h>
#include <stdlib.h>

int	main (void)
{
	printf("%d : %d\n", atoi("\n\t +0123456"), ft_atoi("\n\t +0123456"));
	printf("%d : %d\n", atoi("\n\t +-0123456"), ft_atoi("\n\t +-0123456"));
	return (0);
}
*/