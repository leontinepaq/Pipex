/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 18:32:36 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/02/26 14:41:49 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	wait_for_childs(t_vars *vars)
{
	unsigned int	i;
	int				status;

	i = 0;
	while (i < vars->nb_cmds)
	{
		waitpid((vars->cpid)[i], &status, 0);
		i++;
	}
	return (WEXITSTATUS(status));
}

void	put_child_errors(t_vars *vars)
{
	unsigned int	i;
	char			*err;

	i = 0;
	while (i < vars->nb_cmds)
	{
		err = get_next_line(vars->fd_err_out[i], GNL_READ);
		while (err)
		{
			ft_putstr_fd(err, 2);
			free(err);
			err = get_next_line(vars->fd_err_out[i], GNL_READ);
		}
		i++;
	}
}

void	parent_process(t_vars *vars)
{
	int	exit_code;

	if (vars->fd_in)
		close_fds(vars->fd_in, vars->nb_cmds);
	if (vars->fd_out)
		close_fds(vars->fd_out, vars->nb_cmds);
	if (vars->fd_err_in)
		close_fds(vars->fd_err_in, vars->nb_cmds);
	exit_code = wait_for_childs(vars);
	put_child_errors(vars);
	free_vars(vars);
	exit(exit_code);
}
