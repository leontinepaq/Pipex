/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:27:29 by lpaquatt          #+#    #+#             */
/*   Updated: 2023/12/12 01:58:23 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_len_unslong(unsigned long nb, int len_base)
{
	int	res;

	res = 1;
	while (nb >= (unsigned long)len_base)
	{
		nb /= len_base;
		res++;
	}
	return (res);
}

int	ft_put_nbr(int n)
{
	char	c;
	long	nb;
	int		res;

	res = 0;
	nb = n;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
		res++;
	}
	if (nb > 9)
	{
		ft_put_nbr(nb / 10);
	}
	c = nb % 10 + '0';
	write(1, &c, 1);
	res += ft_len_unslong((unsigned long)nb, 10);
	return (res);
}

int	ft_check_errors(char *base, int len)
{
	int	i;
	int	j;

	if (len < 2)
		return (1);
	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '-' || base[i] == '+')
			return (1);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_put_nbr_base(int nbr, char *base)
{
	char			digit;
	int				len_base;
	unsigned long	long_nbr;
	int				res;

	len_base = 0;
	res = 0;
	while (base[len_base] != '\0')
		len_base ++;
	if (ft_check_errors(base, len_base))
		return (0);
	long_nbr = (unsigned int)nbr;
	if (long_nbr >= (unsigned long)len_base)
	{
		ft_put_nbr_base(long_nbr / len_base, base);
	}
	digit = base[long_nbr % len_base];
	write(1, &digit, 1);
	res += ft_len_unslong((unsigned long)long_nbr, len_base);
	return (res);
}

int	ft_put_nbr_uns(unsigned int nb)
{
	char	c;

	if (nb > 9)
	{
		ft_put_nbr_uns(nb / 10);
	}
	c = nb % 10 + '0';
	write(1, &c, 1);
	return (ft_len_unslong((unsigned long)nb, 10));
}

/*
void	ft_putnbr_dbl_fd(double d, int fd)
{
	char	c;
	int		i;
	int		rk_comma;

	if (d < 0)
	{
		write(fd, "-", 1);
		d = -d;
	}
	rk_comma = 1;
	while (d >= 10)
	{
		d /= 10;
		rk_comma++;
	}
	i = 0;
	while (d - (int)d > 0)
	{
		if (i++ == rk_comma)
			write(fd, ".", 1);
		ft_putnbr_fd((int)d % 10, fd);
		d *= 10;
	}	
	ft_putnbr_fd((int)d % 10, fd);
	write(fd, &c, 1);
}
*/