/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_pipes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:00:30 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/02/26 16:45:21 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	open_pipe_heredoc(t_vars *vars)
{
	int		end[2];
	int		len_limiter;
	char	*content;

	if (pipe(end) == -1)
		exit_process(vars, "pipe", EXIT_FAILURE);
	len_limiter = ft_strlen(vars->here_doc_limiter);
	ft_putstr_fd("pipe heredoc> ", STDIN_FILENO);
	content = get_next_line(STDIN_FILENO, GNL_READ);
	while (content
		&& (!(ft_strncmp(vars->here_doc_limiter, content, len_limiter) == 0
				&& content[len_limiter] == '\n')))
	{
		ft_putstr_fd("pipe heredoc> ", STDIN_FILENO);
		ft_putstr_fd(content, end[WRITE]);
		free(content);
		content = get_next_line(STDIN_FILENO, GNL_READ);
	}
	if (content)
		free(content);
	get_next_line(STDIN_FILENO, GNL_CLEAN);
	return (close(end[WRITE]), end[READ]);
}

int	open_file(char *path, int file_type, t_vars *vars)
{
	int	fd;

	if (file_type == INFILE)
	{
		if (vars->is_here_doc == TRUE)
			fd = open_pipe_heredoc(vars);
		else
			fd = open(path, O_RDONLY);
	}
	if (file_type == OUTFILE)
	{
		if (vars->is_here_doc == TRUE)
			fd = open(path, O_CREAT | O_RDWR | O_APPEND, 0644);
		else
			fd = open(path, O_CREAT | O_RDWR | O_TRUNC, 0644);
	}
	if (fd == -1)
		exit_process(vars, path, EXIT_FAILURE);
	return (fd);
}

void	open_fd_in_out(t_vars *vars)
{
	unsigned int	i;
	int				end[2];

	i = 0;
	vars->fd_in[0] = open_file(vars->infile, INFILE, vars);
	vars->fd_out[vars->nb_cmds - 1] = open_file(vars->outfile, OUTFILE, vars);
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
