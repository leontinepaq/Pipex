/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_fd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:00:30 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/02/20 14:01:28 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	open_file(char *path, int file_type, t_vars *vars)
{
	int	fd;

	if (file_type == INFILE)
		fd = open(path, O_RDONLY);
	if (file_type == OUTFILE)
		fd = open(path, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd == -1)
	{
		perror(path);
		free_vars(vars);
		exit(EXIT_FAILURE);
	}
	return (fd);
}

void	open_fd(t_vars *vars)
{
	unsigned int	i;

	i = 0;
	vars->fd_in[0] = open_file(vars->infile, INFILE, vars);
	vars->fd_out[vars->nb_cmds - 1] = open_file(vars->outfile, OUTFILE, vars);
	while (i < vars->nb_cmds - 1)
	{
		if (pipe((vars->pipe_end)[i]) == -1)
		{
			perror("pipe");
			free_vars(vars);
			exit(EXIT_FAILURE);
		}
		(vars->fd_out)[i] = (vars->pipe_end)[i][WRITE];
		(vars->fd_in)[i + 1] = (vars->pipe_end)[i][READ];
		i++;
	}
}
