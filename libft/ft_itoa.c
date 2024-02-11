/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:58:58 by lpaquatt          #+#    #+#             */
/*   Updated: 2023/11/15 18:02:02 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lennb(long n)
{
	int	len;

	len = 1;
	if (n < 0)
	{
		n = -n;
		len++;
	}
	while (n > 9)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*res;
	long	nb;
	int		lennb;

	nb = n;
	lennb = ft_lennb(nb);
	res = malloc((lennb + 1) * sizeof(char));
	if (!res)
		return (NULL);
	res[lennb--] = '\0';
	if (nb < 0)
	{
		res[0] = '-';
		nb = -nb;
	}
	while (lennb > 0)
	{
		res[lennb] = '0' + nb % 10;
		nb = nb / 10;
		lennb--;
	}
	if (n >= 0)
		res[0] = '0' + nb % 10;
	return (res);
}

/*
char	*ft_itoa(int n)
{
	char	*res;
	char	*prev;
	int		i;
	long	nb;

	nb = n;
	res = malloc((ft_lennb(nb) + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	if (nb < 0)
		res[i++] = '-';
	if (nb >= 10 || n <= -10)
	{
		prev = ft_itoa(n / 10);
		if (!prev)
			return (NULL);
		while (prev[i])
		{
			res[i] = prev[i];
			i++;
		}
	}
	if (nb < 0)
		nb = -nb;
	res[i] = '0' + nb % 10;
	res [i + 1] = '\0';
	return (res);
}
*/

/*
#include <stdio.h>

int	main()
{
	printf("%s\n",ft_itoa(0));
	printf("%s\n",ft_itoa(-1234567890));
}
*/
