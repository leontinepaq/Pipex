/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:41:49 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/02/25 14:52:23 by lpaquatt         ###   ########.fr       */
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
	perror("execve");
	free_vars(vars);
	exit(EXIT_FAILURE);
}

void	dup_filenos(t_vars *vars)
{
	if (dup2(vars->fd_in[vars->index], STDIN_FILENO) == -1
		|| dup2(vars->fd_out[vars->index], STDOUT_FILENO) == -1
		|| dup2(vars->fd_err_in[vars->index], STDERR_FILENO) == -1)
	{
		free_vars(vars);
		perror("dup2");
		exit(EXIT_FAILURE);
	}
}

void	child_process(t_vars *vars)
{
	//printf("PID IS %d\n", getpid());

	dup_filenos(vars);
	check_cmd(vars->cmd[vars->index], vars);
	exec_cmd(vars->cmd[vars->index], vars);
	free_vars(vars);
	exit(EXIT_SUCCESS); //pas utile apres je pense
}
