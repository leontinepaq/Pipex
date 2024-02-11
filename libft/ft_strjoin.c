/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:13:07 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/01/26 13:38:51 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len_s1;
	int		len_s2;
	char	*res;

	if (!s1 && !s2)
		return (NULL);
	len_s1 = 0;
	len_s2 = 0;
	if (s1)
		len_s1 = ft_strlen(s1);
	if (s2)
		len_s2 = ft_strlen(s2);
	res = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!res)
		return (NULL);
	if (s1 && s2)
	{
		ft_strlcpy(res, s1, len_s1 + 1);
		ft_strlcat(res, s2, len_s1 + len_s2 + 1);
	}
	if (s1 != NULL && s2 == NULL)
		ft_strlcpy(res, s1, len_s1 + 1);
	if (s1 == NULL && s2 != NULL)
		ft_strlcpy(res, s2, len_s2 + 1);
	return (res);
}

/*
#include <stdio.h>

int main ()
{
	char *str;
	
	str = ft_strjoin("abc", "defg");
	printf("%s", str);
	free(str);
	return 0;
}
*/
