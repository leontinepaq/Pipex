/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:31:35 by lpaquatt          #+#    #+#             */
/*   Updated: 2023/12/12 01:43:26 by lpaquatt         ###   ########.fr       */
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

int	ft_nb_to_trim(char const *s1, char const *set)
{
	int	nb;
	int	i;

	nb = 0;
	i = 0;
	while (ft_in_set(s1[i], set))
	{
		nb++;
		i++;
	}
	if (!s1[i])
		return (nb);
	i = ft_strlen(s1) - 1;
	while (ft_in_set(s1[i], set))
	{
		nb++;
		i--;
	}
	return (nb);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	int		i;
	int		j;
	int		len_f;

	if (!s1)
		return (NULL);
	len_f = ft_strlen(s1) - ft_nb_to_trim(s1, set);
	res = malloc((len_f + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (ft_in_set(s1[i], set))
		i++;
	j = 0;
	while (j < len_f)
	{
		res[j] = s1[i];
		i++;
		j++;
	}
	res[j] = '\0';
	return (res);
}

/*
#include <stdio.h>

int main ()
{
	printf("test1 : %s\n", ft_strtrim("-test1*","-*"));
	printf("test2 : %s\n", ft_strtrim("test2","-*"));
	printf("test*3 : %s\n", ft_strtrim("-*-*test*3-*","-*"));	
	printf("lorem ipsum \t dolor sit \t amet : %s\n", ft_strtrim("lorem ipsum 
	\t dolor sit \t amet"," "));
}
*/
