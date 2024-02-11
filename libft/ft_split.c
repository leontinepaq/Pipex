/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:23:32 by lpaquatt          #+#    #+#             */
/*   Updated: 2023/11/15 18:39:50 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_words(char *str, char c)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (str[i] != '\0')
	{
		while (str[i] == c)
			i++;
		if (str[i] != '\0')
			cnt++;
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	return (cnt);
}

char	*ft_split_str(char **res, char *str, char c)
{
	int		index;
	int		tab_num;
	int		len_word;

	index = 0;
	tab_num = 0;
	while (str[index] != '\0')
	{
		while (str[index] == c)
			index++;
		len_word = 0;
		while (str[index + len_word] != c && str[index + len_word] != '\0')
			len_word++;
		if (len_word > 0)
		{
			res[tab_num] = ft_substr(str, index, len_word);
			if (res[tab_num] == NULL)
				return (NULL);
			index = index + len_word;
			tab_num++;
		}
	}
	res[tab_num] = NULL;
	return (res[tab_num - 1]);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	char	*str;
	int		i;

	if (!s)
		return (NULL);
	str = (char *)s;
	res = malloc((ft_count_words(str, c) + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	if (ft_count_words(str, c) == 0)
	{
		res[0] = NULL;
		return (res);
	}
	if (!ft_split_str(res, str, c))
	{
		i = 0;
		while (res[i])
			free(res[i++]);
		free(res);
		return (NULL);
	}
	return (res);
}

/*
#include <stdio.h>

int	main(void)
{
	char **tab;

	tab = ft_split("Coucou tout le monde! ",' ');
	printf("%s/%s/%s/%s\n",tab[0], tab[1], tab[2], tab[3]);
	tab = ft_split("   Coucou - \n tout le ---- monde!   ",'\n');
	printf("%s/%s\n",tab[0], tab[1]);
	free(tab[0]);
	free(tab[1]);
	free(tab);


	tab = ft_split("",'z');
	printf("%s %s\n",tab[0], tab[1]);
	free(tab[0]);
	free(tab[1]);
	free(tab);
}
*/
