/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:56:17 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/02/22 13:10:20 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	fork_processes(t_vars *vars)
{
	while (vars->index < vars->nb_cmds)
	{
		vars->cpid[vars->index] = fork();
		if (vars->cpid[vars->index] == -1)
		{
			perror("fork");
			free_vars(vars);
			exit(EXIT_FAILURE);
		}
		if (vars->cpid[vars->index] == 0)
			child_process(vars);
		vars->index++;
	}
	parent_process(vars);
}

int	main(int ac, char **av, char **envp)
{
	t_vars	*vars;

//	printf("PARENT PID IS %d\n", getpid());
	if (ac < 5)
		return (ft_putstr_fd("Error\nInvalid number of args\n", 2), EXIT_FAILURE);
	vars = init_vars(ac, av, envp);
	open_pipes(vars);
	fork_processes(vars);
	free_vars(vars);
	return (EXIT_SUCCESS);
}
