/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_vars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:35:18 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/02/16 18:01:36 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_argv(char **argv)
{
	int	i;

	if (!argv)
		return ;
	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

void	free_cmd(t_cmd *cmd)
{
	if (!cmd)
		return ;
	if (cmd->path)
		free(cmd->path);
	free_argv(cmd->argv);
	free(cmd);
}

void	free_cmds(t_cmd **cmds, int nb_cmds)
{
	int	i;

	i = 0;
	while (i < nb_cmds)
	{
		if (!cmds[i])
			return ;
		free_cmd(cmds[i]);
		i++;
	}
	free(cmds);
}

void	free_pipe_end(int **pipe_end, int nb_cmds)
{
	int	i;

	i = 0;
	while (i < nb_cmds)
	{
		if (!pipe_end[i])
			return ;
		free(pipe_end[i]);
		i++;
	}
	free(pipe_end);
}

void	close_fds(int	*fd, int nb_cmds)
{
	int	i;

	i = 0;
	while (i < nb_cmds)
	{
		if (fd[i] != -1)
			close(fd[i]);
		i++;
	}
	free(fd);
}

void	free_vars(t_vars *vars)
{
	if (vars->fd_in)
		close_fds(vars->fd_in, vars->nb_cmds);
	if (vars->fd_out)
		close_fds(vars->fd_out, vars->nb_cmds);
	if (vars->err_out)
		free(vars->err_out);
	if (vars->cmds)
		free_cmds(vars->cmds, vars->nb_cmds);
	if (vars->pipe_end)
		free_pipe_end(vars->pipe_end, vars->nb_cmds);
	free(vars);
}
