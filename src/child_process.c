/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:41:49 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/02/26 17:17:21 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	exec_cmd(t_cmd *cmd, t_vars *vars)
{
	if (vars->fd_in)
		close_fds(vars->fd_in, vars->nb_cmds);
	if (vars->fd_out)
		close_fds(vars->fd_out, vars->nb_cmds);
	if (vars->fd_err_in)
		close_fds(vars->fd_err_in, vars->nb_cmds);
	if (vars->fd_err_out)
		close_fds(vars->fd_err_out, vars->nb_cmds);
	execve(cmd->path, cmd->argv, vars->envp);
	exit_process(vars, "execve", EXIT_FAILURE);
}

void	dup_filenos(t_vars *vars)
{
	if (dup2(vars->fd_in[vars->index], STDIN_FILENO) == -1
		|| dup2(vars->fd_out[vars->index], STDOUT_FILENO) == -1
		|| dup2(vars->fd_err_in[vars->index], STDERR_FILENO) == -1)
		exit_process(vars, "dup2", EXIT_FAILURE);
}

void	child_process(t_vars *vars)
{
	unsigned int	index_max;

	index_max = vars->nb_cmds - 1;
	if (vars->index == 0)
		vars->fd_in[0] = open_file(vars->infile, INFILE, vars);
	if (vars->index == index_max)
		vars->fd_out[index_max] = open_file(vars->outfile, OUTFILE, vars);
	dup_filenos(vars);
	check_cmd(vars->cmd[vars->index], vars);
	exec_cmd(vars->cmd[vars->index], vars);
	free_vars(vars);
	exit(EXIT_SUCCESS);
}
