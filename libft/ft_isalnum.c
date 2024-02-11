/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: lpaquatt <marvin@42.fr>		    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/11/06 14:07:45 by lpaquatt	       #+#    #+#	      */
/*   Updated: 2023/11/06 14:12:30 by lpaquatt         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9'))
		return (1);
	return (0);
}

/*
#include <stdio.h>
#include <ctype.h>

int	main(void)
{
	printf("%d : %d\n", isalnum('n'), ft_isalnum('n'));
	printf("%d : %d\n", isalnum('0'), ft_isalnum('0'));
	printf("%d : %d\n", isalnum(' '), ft_isalnum(' '));
	printf("%d : %d\n", isalnum(1), ft_isalnum(1));
//    printf("%d : %d\n", isalpha("N"), ft_isalpha("N"));
	return (0);
}
*/
