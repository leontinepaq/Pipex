/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:56:17 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/02/16 18:04:35 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


void	open_fd(t_vars *vars)
{
	int	i;

	i = 0;
	vars->fd_in[0] = open(vars->infile, O_RDONLY);
	vars->fd_out[vars->nb_cmds - 1] = open(vars->outfile, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (!vars->fd_in[0] || !vars->fd_out[vars->nb_cmds - 1])
	{
		perror("Error"); // ??
		free_vars(vars);
		exit(EXIT_FAILURE);
	}
	while (i < vars->nb_cmds - 1)
	{
		if (pipe((vars->pipe_end)[i]) == -1)
		{
			perror("Error"); // ??
			free_vars(vars);
			exit(EXIT_FAILURE);
		}
		(vars->fd_out)[i] = (vars->pipe_end)[i][WRITE];
		(vars->fd_in)[i + 1] = (vars->pipe_end)[i][READ];
		i++;
	}
}

int		main(int ac, char **av)
{
	t_vars	*vars;

	vars = init_vars(ac, av);
	open_fd(vars);

	free_vars(vars);
	return (EXIT_SUCCESS);
}
