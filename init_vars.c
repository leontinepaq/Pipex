/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 17:07:58 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/02/16 18:06:25 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_fd(int **fd, t_vars *vars)
{
	int	i;

	*fd = malloc(vars->nb_cmds * sizeof(int));
	if (!*fd)
	{
		free_vars(vars);
		ft_putstr_fd(ERR_MALLOC, 2);
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
	int	i;

	*pipe_end = malloc(vars->nb_cmds * sizeof(int *));
	if (!*pipe_end)
	{
		free_vars(vars);
		ft_putstr_fd(ERR_MALLOC, 2);
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (i < vars->nb_cmds)
	{
		(*pipe_end)[i] = malloc(sizeof(t_cmd));
		if (!(*pipe_end)[i])
		{
			free_vars(vars);
			ft_putstr_fd(ERR_MALLOC, 2);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

void	init_cmds(t_vars *vars, char **av)
{
	int	i;

	i = 0;
	vars->cmds = malloc(vars->nb_cmds * sizeof(t_cmd *));
	if (!vars->cmds)
	{
		free_vars(vars);
		ft_putstr_fd(ERR_MALLOC, 2);
		exit(EXIT_FAILURE);
	}
	while (i < vars->nb_cmds)
	{
		vars->cmds[i] = malloc(sizeof(t_cmd));
		if (!vars->cmds[i])
		{
			free_vars(vars);
			ft_putstr_fd(ERR_MALLOC, 2);
			exit(EXIT_FAILURE);
		}
		(vars->cmds[i])->argv = NULL;
		(vars->cmds[i])->path = NULL;
		(vars->cmds[i])->cmd = av[i + 1];
		i++;
	}
}


t_vars	*init_vars(int ac, char **av)
{
	t_vars	*vars;

	vars = malloc(sizeof(t_vars));
	if (!vars)
	{
		ft_putstr_fd(ERR_MALLOC, 2);
		exit(EXIT_FAILURE);
	}
	vars->nb_cmds = ac - 1;
	vars->pipe_end = NULL;
	vars->fd_in = NULL;
	vars->fd_out = NULL;
	vars->cmds = NULL;
	vars->infile = av[1];
	vars->outfile = av[ac - 1];
	vars->err_out = malloc(vars->nb_cmds * sizeof(int));
	if (!vars->err_out)
	{
		free_vars(vars);
		ft_putstr_fd(ERR_MALLOC, 2);
		exit(EXIT_FAILURE);
	}
	init_pipe_end(&vars->pipe_end, vars);
	init_fd(&vars->fd_in, vars);
	init_fd(&vars->fd_out, vars);
	init_cmds(vars, av);
	return (vars);
}
