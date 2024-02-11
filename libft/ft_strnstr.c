/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:54:41 by lpaquatt          #+#    #+#             */
/*   Updated: 2023/11/15 18:34:01 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	if (ft_strlen(little) == 0 || (big == NULL && len == 0))
		return ((char *)big);
	i = 0;
	while (big[i] && i + ft_strlen(little) <= len)
	{
		if (ft_strncmp(&((char *)big)[i], (char *)little,
			ft_strlen((char *)little)) == 0)
			return (&((char *)big)[i]);
		i++;
	}
	return (NULL);
}

/*
#include <stdio.h>
#include <bsd/bsd.h>
#include <bsd/string.h>

int	main(void)
{
	char * empty = (char*)"";
	
	printf("%s : %s\n", "abc",ft_strnstr("abc","abc",4));
	printf("%s : %s\n", "abc", ft_strnstr("abc","abc",2));
	printf("%s : %s\n", "(null)",ft_strnstr("abcdef","def",4));
	printf("%s : %s\n","(null)",ft_strnstr("abcdef","f",4));
	printf("%s : %s\n","def",ft_strnstr("abcdef","def",10));
	printf("%s : %s\n","",ft_strnstr(empty,"",-1));	
	printf("%s : %s\n","(null)",ft_strnstr("aaabcabcd","cd",8));
	printf("%s : %s\n","(null)",ft_strnstr("aaabcabcd","aabc",0));	

	return (0);

}
*/
