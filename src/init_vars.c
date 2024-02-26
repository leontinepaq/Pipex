/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 17:07:58 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/02/26 15:45:30 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	init_fd(int **fd, t_vars *vars)
{
	unsigned int	i;

	*fd = malloc(vars->nb_cmds * sizeof(int));
	if (!*fd)
		exit_process(vars, "malloc", EXIT_FAILURE);
	i = 0;
	while (i < vars->nb_cmds)
	{
		(*fd)[i] = -1;
		i++;
	}
}

void	init_cmds(t_vars *vars, char **av)
{
	unsigned int	i;

	i = 0;
	vars->cmd = malloc(vars->nb_cmds * sizeof(t_cmd *));
	if (!vars->cmd)
		exit_process(vars, "malloc", EXIT_FAILURE);
	while (i < vars->nb_cmds)
	{
		vars->cmd[i] = malloc(sizeof(t_cmd));
		if (!(vars->cmd[i]))
			exit_process(vars, "malloc", EXIT_FAILURE);
		(vars->cmd[i])->argv = NULL;
		(vars->cmd[i])->path = NULL;
		(vars->cmd[i])->cmd = av[i + 2 + vars->is_here_doc];
		i++;
	}
}

t_vars	*malloc_vars(void)
{
	t_vars	*vars;

	vars = malloc(sizeof(t_vars));
	if (!vars)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	vars->fd_in = NULL;
	vars->fd_out = NULL;
	vars->fd_err_in = NULL;
	vars->fd_err_out = NULL;
	vars->cmd = NULL;
	vars->here_doc_limiter = NULL;
	return (vars);
}

t_vars	*init_vars(int ac, char **av, char **envp)
{
	t_vars	*vars;

	vars = malloc_vars();
	vars->is_here_doc = (ft_strncmp(av[1], "here_doc", 9) == 0);
	if (vars->is_here_doc == TRUE)
		vars->here_doc_limiter = av[2];
	vars->nb_cmds = (unsigned int)ac - 3 - vars->is_here_doc;
	vars->index = 0;
	vars->infile = av[1];
	vars->outfile = av[ac - 1];
	vars->envp = envp;
	vars->cpid = malloc(vars->nb_cmds * sizeof(pid_t));
	if (!vars->cpid)
		exit_process(vars, "malloc", EXIT_FAILURE);
	init_fd(&vars->fd_in, vars);
	init_fd(&vars->fd_out, vars);
	init_fd(&vars->fd_err_in, vars);
	init_fd(&vars->fd_err_out, vars);
	init_cmds(vars, av);
	init_paths_list(vars, envp);
	return (vars);
}
