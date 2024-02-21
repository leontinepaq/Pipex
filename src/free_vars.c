/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_vars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:35:18 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/02/21 17:42:02 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	free_cmd(t_cmd *cmd)
{
	if (!cmd)
		return ;
	ft_free_tab((void **)cmd->argv);
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

void	close_fds(int *fd, unsigned int nb_cmds)
{
	unsigned int	i;

	i = 0;
	while (i < nb_cmds)
	{
		if (fd[i] != -1)
			close(fd[i]);
		fd[i] = -1;
		i++;
	}
}

void	free_fds(int *fd, unsigned int nb_cmds)
{
	close_fds(fd, nb_cmds);
	free(fd);
}

void	free_vars(t_vars *vars)
{
	if (vars->fd_in)
		free_fds(vars->fd_in, vars->nb_cmds);
	if (vars->fd_out)
		free_fds(vars->fd_out, vars->nb_cmds);
	if (vars->fd_err_in)
		free_fds(vars->fd_err_in, vars->nb_cmds);
	if (vars->fd_err_out)
		free_fds(vars->fd_err_out, vars->nb_cmds);
	if (vars->cpid)
		free(vars->cpid);
	if (vars->cmd)
		free_cmds(vars->cmd, vars->nb_cmds);
	if (vars->paths_list)
		ft_free_tab((void **)vars->paths_list);
	free(vars);
}
