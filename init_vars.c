/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 17:07:58 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/02/20 18:56:36 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_fd(int **fd, t_vars *vars)
{
	unsigned int	i;

	*fd = malloc(vars->nb_cmds * sizeof(int));
	if (!*fd)
	{
		free_vars(vars);
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (i < vars->nb_cmds)
	{
		(*fd)[i] = -1;
		i++;
	}
}

void	init_pipe_end(int ***pipe_end, t_vars *vars)
{
	unsigned int	i;

	*pipe_end = malloc(vars->nb_cmds * sizeof(int *));
	if (!*pipe_end)
	{
		free_vars(vars);
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (i < vars->nb_cmds)
	{
		(*pipe_end)[i] = malloc(sizeof(t_cmd));
		if (!((*pipe_end)[i]))
		{
			ft_printf("TEST\n");
			free_vars(vars);
			perror("malloc");
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

void	init_cmds(t_vars *vars, char **av)
{
	unsigned int	i;

	i = 0;
	vars->cmd = malloc(vars->nb_cmds * sizeof(t_cmd *));
	if (!vars->cmd)
	{
		free_vars(vars);
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	while (i < vars->nb_cmds)
	{
		vars->cmd[i] = malloc(sizeof(t_cmd));
		if (!(vars->cmd[i]))
		{
			free_vars(vars);
			perror("malloc");
			exit(EXIT_FAILURE);
		}
		(vars->cmd[i])->argv = NULL;
		(vars->cmd[i])->path = NULL;
		(vars->cmd[i])->cmd = av[i + 2];
		i++;
	}
}

t_vars	*malloc_vars(void)
{
	t_vars	*vars;

	vars = malloc(sizeof(t_vars));
	if (!vars)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	vars->pipe_end = NULL;
	vars->fd_in = NULL;
	vars->fd_out = NULL;
	vars->err_out = NULL;
	vars->cmd = NULL;
	return (vars);
}

t_vars	*init_vars(int ac, char **av, char **envp)
{
	t_vars	*vars;

	vars = malloc_vars();
	vars->nb_cmds = (unsigned int)ac - 3;
	vars->index = 0;
	vars->infile = av[1];
	vars->outfile = av[ac - 1];
	vars->err_out = malloc(vars->nb_cmds * sizeof(int));
	vars->cpid = malloc(vars->nb_cmds * sizeof(pid_t));
	if (!vars->err_out || !vars->cpid)
	{
		free_vars(vars);
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	init_pipe_end(&vars->pipe_end, vars);
	init_fd(&vars->fd_in, vars);
	init_fd(&vars->fd_out, vars);
	init_cmds(vars, av);
	init_paths_list(vars, envp);
	return (vars);
}
