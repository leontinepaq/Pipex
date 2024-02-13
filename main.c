/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 17:22:52 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/02/13 13:39:52 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	child_process(int fd, int *end, t_cmd *cmd, char**envp)
{
	if (dup2(fd, STDIN_FILENO) == -1)
		return (perror("dup2"), EXIT_FAILURE);
	if (dup2(end[1], STDOUT_FILENO) == -1)
		return (perror("dup2"), EXIT_FAILURE);
	close_end(end);
//	close(fd);
	(void) cmd;
	(void) envp;
	//execve(cmd->path, cmd->argv, envp);
	perror("execve");
	return (EXIT_FAILURE);
}

int	parent_process(int *end, int fd, t_cmd *cmd, char**envp)
{
	if (dup2(end[0], STDIN_FILENO) == -1)
		return (perror("dup2"), EXIT_FAILURE);
	if (dup2(fd, STDOUT_FILENO) == -1)
		return (perror("dup2"), EXIT_FAILURE);
	close_end(end);
	close(fd);
	execve(cmd->path, cmd->argv, envp);
	perror("execve");
	return (EXIT_FAILURE);
}


int pipex(int fd1, int fd2, char **av, char **envp)
{
	int		end[2];
	pid_t	cpid;
	t_cmd	*cmd1;
	t_cmd	*cmd2;

	cmd1 = split_command(av[2], envp);
	cmd2 = split_command(av[3], envp);
	if (!cmd1 | !cmd2)
		return (free_cmd(cmd1), free_cmd(cmd2), EXIT_FAILURE);
	// proteger les cmd une par une ..?
	if (pipe(end) == -1)
		return (perror("Pipe"), free_cmd(cmd1), free_cmd(cmd2), EXIT_FAILURE);
	cpid = fork();
	if (cpid == -1)
		return (perror("Fork"), close_end(end), free_cmd(cmd1), free_cmd(cmd2), EXIT_FAILURE);
	if (cpid == 0)
		child_process(fd1, end, cmd1, envp);
	else
		parent_process(end, fd2, cmd2, envp);
	free_cmd(cmd1);
	free_cmd(cmd2);
	return (EXIT_SUCCESS);
}

int main(int ac, char **av, char **envp)
{
	int	fd1;
	int fd2;

	if (ac != 5)
	{
		ft_putstr_fd(ERR_NB_ARGS, 2);
		return (EXIT_FAILURE);
	}
	fd1 = open(av[1], O_RDONLY);
	fd2 = open(av[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	// pk 644 ? (User RW group R other R)
	if (fd1 < 0 || fd2 < 0)
		return (perror("Error\nOpening file"), EXIT_FAILURE);
	if (pipex(fd1, fd2, av, envp) == EXIT_FAILURE)
		return (close(fd1), close(fd2), EXIT_FAILURE);
	close(fd1);
	close(fd2);
	return (EXIT_SUCCESS);
}
