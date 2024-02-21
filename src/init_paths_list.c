/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_paths_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 18:56:09 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/02/21 16:49:42 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	append_paths(char **paths_list)
{
	int		i;
	char	*tmp;

	if (!paths_list)
		return ;
	i = 0;
	while (paths_list[i])
	{
		tmp = ft_strjoin(paths_list[i], "/");
		if (!tmp)
		{
			ft_free_tab((void **)paths_list);
			perror("append_path");
			return ;
		}
		free(paths_list[i]);
		paths_list[i] = tmp;
		i++;
	}
}

void	init_paths_list(t_vars *vars, char **envp)
{
	int		i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp("PATH=", envp[i], 5) == 0)
		{
			vars->paths_list = ft_split(envp[i] + 5, ':');
			if (!vars->paths_list)
				perror("malloc");
			break ;
		}
		i++;
	}
	append_paths(vars->paths_list);
}
