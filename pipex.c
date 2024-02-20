/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:56:17 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/02/20 19:48:23 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

void	find_cmd_path(t_cmd *cmd, t_vars *vars, unsigned int index)
{
	cmd->path = ft_strdup(cmd->argv[0]);
	if (access_via_envt(cmd, vars) == 0)
		return ;
	if (access(cmd->path, F_OK) == 0)
		return ;
	vars->err_out[index] = errno;
	free_vars(vars);
	exit(EXIT_FAILURE);
}

void	check_cmd(t_cmd *cmd, t_vars *vars, unsigned int index)
{
	cmd->argv = ft_split(cmd->cmd, ' ');
	ft_printf("GIVEN PATH : %s\n", cmd->argv[0]);
	if (!cmd->argv)
	{
		
	}
	find_cmd_path(cmd, vars, index);
	ft_printf("FINAL PATH : %s\n", cmd->path);
//	check_access(cmd);
	(void) vars;
}

void	exec_child_cmd(t_vars *vars, unsigned int index)
{
	check_cmd(vars->cmd[vars->index], vars, index);
//	exec_cmd(vars->cmd[vars->index], vars);
 
	free_vars(vars);
	exit(EXIT_SUCCESS); //pas utile apres je pense
}

void	exec_cmds(t_vars *vars)
{
	while (vars->index < vars->nb_cmds)
	{
		vars->cpid[vars->index] = fork();
		if (vars->cpid[vars->index] == -1)
		{
			perror("fork");
			free_vars(vars);
			exit(EXIT_FAILURE);
		}
		if (vars->cpid[vars->index] == 0)
		{
			ft_printf("EXEC CHILD %d\n", vars->index);
			exec_child_cmd(vars, vars->index);
		}
		vars->index++;
	}
//	waitpid(vars); // le parent attend que les enfants aient fini
}


int		main(int ac, char **av, char **envp)
{
	t_vars	*vars;

	if (ac < 5)
		return (ft_putstr_fd("Error\nInvalid number of args\n", 2), EXIT_FAILURE);
	vars = init_vars(ac, av, envp);
	open_fd(vars);
	/*
	unsigned int i = 0;
	while (i < vars->nb_cmds)
	{
		ft_printf("cdm %d/%d: %s\n", i + 1, vars->nb_cmds, (vars->cmd[i])->cmd);
		i++;
	}
	*/
	exec_cmds(vars);
	free_vars(vars);
	return (EXIT_SUCCESS);
}
