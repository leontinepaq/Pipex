/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:58:51 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/02/21 18:16:58 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	access_via_envt(t_cmd *cmd, t_vars *vars)
{
	unsigned int	i;
	char			*path;

	i = 0;
	while ((vars->paths_list)[i])
	{
		path = ft_strjoin((vars->paths_list)[i], cmd->path);
		if (!path)
		{
			perror("malloc");
			free_vars(vars);
			exit(EXIT_FAILURE);
		}
		if (access(path, F_OK) == 0)
		{
			free(cmd->path);
			cmd->path = path;
			return (0);
		}
		i++;
		free(path);
	}
	return (-1);
}

int	is_path(char *str)
{
	if (!str)
		return (FALSE);
	if (ft_strlen(str) < 2)
		return (FALSE);
	if (str[0] == '/')
		return (TRUE);
	if (str[0] == '~' && str[1] == '/')
		return (TRUE);
	if (str[0] == '.' && (str[1] == '/' || (str[1] == '.' && str[2] == '/')))
		return (TRUE);
	return (FALSE);
}

void	find_cmd_path(t_cmd *cmd, t_vars *vars)
{
	cmd->path = ft_strdup(cmd->argv[0]);
	if (is_path(cmd->path) == FALSE)
	{
		if (access_via_envt(cmd, vars) == 0)
			return ;
		ft_putstr_fd(cmd->path, 2);
		ft_putstr_fd(" : command not found\n", 2);
		free_vars(vars);
		exit(127);
	}
	else
	{
		if (access(cmd->path, F_OK) == 0)
			return ;
		perror(cmd->path);
		free_vars(vars);
		exit(127);
	}
}

void	check_exec(t_cmd *cmd, t_vars *vars)
{
	if (access(cmd->path, X_OK) == 0)
		return ;
	perror(cmd->path);
	free_vars(vars);
	exit(126);
}

void	check_cmd(t_cmd *cmd, t_vars *vars)
{
	cmd->argv = ft_split(cmd->cmd, ' ');
	if (!cmd->argv)
	{
		perror("malloc");
		free_vars(vars);
		exit(EXIT_FAILURE);
	}
	find_cmd_path(cmd, vars);
	check_exec(cmd, vars);
}
