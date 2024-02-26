/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_pipes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:00:30 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/02/26 17:18:51 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	open_fd_in_out(t_vars *vars)
{
	unsigned int	i;
	int				end[2];

	i = 0;
	while (i < vars->nb_cmds - 1)
	{
		if (pipe(end) == -1)
			exit_process(vars, "pipe", EXIT_FAILURE);
		(vars->fd_out)[i] = end[WRITE];
		(vars->fd_in)[i + 1] = end[READ];
		i++;
	}
}

void	open_fd_err_in_out(t_vars *vars)
{
	unsigned int	i;
	int				end[2];

	i = 0;
	while (i < vars->nb_cmds)
	{
		if (pipe(end) == -1)
			exit_process(vars, "pipe", EXIT_FAILURE);
		(vars->fd_err_in)[i] = end[WRITE];
		(vars->fd_err_out)[i] = end[READ];
		i++;
	}
}

void	open_pipes(t_vars *vars)
{
	open_fd_in_out(vars);
	open_fd_err_in_out(vars);
}
