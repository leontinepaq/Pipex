/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_vars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:35:18 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/02/20 18:53:24 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_argv(char **argv)
{
	unsigned int	i;

	if (!argv)
		return ;
	i = 0;
	while (argv[i])
	{
		if (!argv[i])
			break ;
		free(argv[i]);
		i++;
	}
	free(argv);
}

void	free_cmd(t_cmd *cmd)
{
	if (!cmd)
		return ;
	free_argv(cmd->argv);
	if (cmd->path)
	 	free(cmd->path);
	free(cmd);
}

void	free_cmds(t_cmd **cmds, unsigned int nb_cmds)
{
	unsigned int	i;

	if (!cmds)
		return ;
	i = 0;
	while (i < nb_cmds)
	{
		if (!cmds[i])
			break ;
		free_cmd(cmds[i]);
		i++;
	}
	free(cmds);
}

void	free_pipe_end(int **pipe_end, unsigned int nb_cmds)
{
	unsigned int	i;

	i = 0;
	while (i < nb_cmds)
	{
		if (!pipe_end[i])
			break ;
		free(pipe_end[i]);
		i++;
	}
	free(pipe_end);
}

void	close_fds(int	*fd, unsigned int nb_cmds)
{
	unsigned int	i;

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
	if (vars->cpid)
		free(vars->cpid);
	if (vars->cmd)
		free_cmds(vars->cmd, vars->nb_cmds);
	if (vars->pipe_end)
		free_pipe_end(vars->pipe_end, vars->nb_cmds);
	if (vars->paths_list)
		free_argv(vars->paths_list);
	free(vars);
}
