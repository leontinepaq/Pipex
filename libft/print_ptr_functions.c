/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:59:25 by lpaquatt          #+#    #+#             */
/*   Updated: 2023/12/12 01:58:38 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_put_str(char *str)
{
	if (!str)
		return (ft_put_str("(null)"));
	write(1, str, ft_strlen(str));
	return (ft_strlen(str));
}

void	ft_puthex(unsigned long long nb, int prev, int *cnt)
{
	char	*base;

	base = "0123456789abcdef";
	if (nb < 16 && prev == 1)
	{
		ft_putchar_fd('0', 1);
		*cnt = *cnt + 1;
	}
	if (nb >= 16)
	{
		ft_puthex(nb / 16, 0, cnt);
		ft_puthex(nb % 16, 0, cnt);
	}
	else
	{
		ft_putchar_fd(base[nb], 1);
		*cnt = *cnt + 1;
	}
}

int	ft_put_ptradd(void *ptr)
{
	unsigned char		*c;
	unsigned long long	addr;
	int					res;

	if (!ptr)
		return (ft_put_str("(nil)"));
	c = ptr;
	addr = (unsigned long long)c;
	ft_put_str("0x");
	res = 2;
	ft_puthex(addr, 0, &res);
	return (res);
}
