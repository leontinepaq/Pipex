/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:28:55 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/02/13 13:26:11 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
			free_argv(paths_list);
			perror("append_path");
			return ;
		}
		free(paths_list[i]);
		paths_list[i] = tmp;
		i++;
	}
}

char	**find_list_paths(char **envp)
{
	int		i;
	char	**paths_list;

	i = 0;
	paths_list = NULL;
	while (envp[i])
	{
		if (ft_strncmp("PATH=", envp[i], 5) == 0)
		{
			paths_list = ft_split(envp[i] + 5, ':');
			if (!paths_list)
				perror("find_list_paths");
			break ;
		}
		i++;
	}
	append_paths(paths_list);
	return (paths_list);
}

t_cmd	*init_cmd(char **argv)
{
	t_cmd	*cmd;

	if (!argv)
		return (NULL);
	cmd = malloc(sizeof(t_cmd));
	if (!cmd)
		return (free_argv(argv), NULL);
	cmd->argv = argv;
	cmd->path = NULL;
	return (cmd);
}

t_cmd	*split_command(char *av, char**envp)
{
	t_cmd	*cmd;
	char	**paths_list;
	int		i;

	paths_list = find_list_paths(envp);
	if (!paths_list)
		return (NULL);
	cmd = init_cmd(ft_split(av, ' '));
	if (!cmd)
		return (perror("split_command"), free_argv(paths_list), NULL);
	i = 0;
	while (paths_list[i])
	{
		cmd->path = ft_strjoin(paths_list[i], cmd->argv[0]);
		if (!cmd->path)
		{
			perror("split_command");
			return (free_argv(paths_list), free_cmd(cmd), NULL);
		}
		if (access(cmd->path, X_OK) == 0)
			return (free_argv(paths_list), cmd);
		i++;
		free(cmd->path);
	}
	ft_printf("%s", cmd->argv[0]);
	//pour avoir nom de la cmd mais print sur sortie standard..?
	perror(" ");
	return (free_argv(paths_list), free_cmd(cmd), NULL);
}
