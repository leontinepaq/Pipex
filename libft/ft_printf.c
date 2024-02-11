/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:49:32 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/01/19 11:17:47 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_in_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_print_args(va_list args, char type)
{
	if (type == 'c')
		return (ft_putchar_fd(va_arg(args, int), 1), 1);
	else if (type == 's')
		return (ft_put_str(va_arg(args, char *)));
	else if (type == 'p')
		return (ft_put_ptradd(va_arg(args, void *)));
	else if (type == 'd' || type == 'i')
		return (ft_put_nbr(va_arg(args, int)));
	else if (type == 'u')
		return (ft_put_nbr_uns(va_arg(args, unsigned int)));
	else if (type == 'x')
		return (ft_put_nbr_base(va_arg(args, int), "0123456789abcdef"));
	else if (type == 'X')
		return (ft_put_nbr_base(va_arg(args, int), "0123456789ABCDEF"));
	else if (type == '%')
		return (ft_putchar_fd('%', 1), 1);
	return (0);
}

int	ft_printf(const char *format_str, ...)
{
	va_list	args;
	int		i;
	int		res;

	va_start(args, format_str);
	i = 0;
	res = 0;
	while (format_str[i])
	{
		if (format_str[i] == '%' && ft_in_set(format_str[i + 1], "cspdiuxX%"))
		{
			res += ft_print_args(args, format_str[i + 1]);
			i += 2;
		}
		else
		{
			ft_putchar_fd(format_str[i], 1);
			res++;
			i++;
		}
	}
	va_end (args);
	return (res);
}
/*
#include <stdio.h>

int	main (void)
{

	//ft_printf("- %c\n- %s\n- %p\n- %d\n- %i\n- %u\n- %x\n- %X\n- %%\n",
	//'c', "str", str, 033, 15, (unsigned int)4294967295, 15, 15);
	//printf("-------------------\n");
	printf("- %c\n- %s\n- %p\n- %d\n- %i\n- %u\n- %x\n- %X\n- %%\n", 'c', 
	"str", str, 033, 15, (unsigned int)4294967295, 15, 15);

	printf("ft_printf : %d\n", ft_printf("%x\n", -15));
	printf("printtf : %d\n", printf("%x\n", -15));
	return (0);
}
*/
