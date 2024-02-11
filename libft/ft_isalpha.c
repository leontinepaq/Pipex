/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: lpaquatt <marvin@42.fr>		    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/11/06 14:08:47 by lpaquatt	       #+#    #+#	      */
/*   Updated: 2023/11/06 14:22:14 by lpaquatt         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

/*
#include <stdio.h>
#include <ctype.h>

int	main(void)
{
	printf("%d : %d\n", isalpha('n'), ft_isalpha('n'));
	printf("%d : %d\n", isalpha('M'), ft_isalpha('M'));
    printf("%d : %d\n", isalpha(' '), ft_isalpha(' '));
    printf("%d : %d\n", isalpha(1), ft_isalpha(1));
//    printf("%d : %d\n", isalpha("N"), ft_isalpha("N"));
	return (0);
}
*/
