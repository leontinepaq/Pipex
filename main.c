/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 17:22:52 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/02/13 09:22:38 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	child_process(int fd, int *end, t_cmd *cmd, char**envp)
{
	close(end[0]);
	dup2(fd, STDIN_FILENO);
	dup2(end[1], STDOUT_FILENO);
	close(end[1]);
	close(fd);
	execve(cmd->path, cmd->argv, envp);
	perror("execve");
	return (EXIT_FAILURE);
}

int	parent_process(int *end, int fd, t_cmd *cmd, char**envp)
{
	close(end[1]);
	dup2(end[0], STDIN_FILENO);
	dup2(fd, STDOUT_FILENO);
	close(end[1]);
	close(fd);
	execve(cmd->path, cmd->argv, envp);
	perror("execve");
	return (EXIT_FAILURE);
}

t_cmd   *split_command(char *av, char**envp)
{
	t_cmd	*cmd;
	char	*path_from_envp;
	char	**paths_list;
	int		i;
	char	*path_cmd;

	cmd = malloc(sizeof(t_cmd)); //faire une fonction a part et initialiser argv et path
	if (!cmd)
		return (perror(ERR_MALLOC), NULL);
	path_from_envp = "/usr/bin";
	(void) envp;
//  path_from_envp = find_list_paths(envp);
	paths_list = ft_split(path_from_envp, ' ');
	if (!paths_list)
		return (perror("Error\nSplit command"), NULL); 
//		return (perror("Error\nSplit command"), free(path_from_envp),free_cmd(cmd), NULL);
	cmd->argv = ft_split(av, ' ');
	if (!cmd)
		return (perror("Error\nSplit command"), free_argv(paths_list), free_cmd(cmd), NULL);
//		return (perror("Error\nSplit command"), free(path_from_envp), free_argv(paths_list), free_cmd(cmd), NULL);
	i = 0;
	while (paths_list[i])
	{
		cmd->path = ft_strjoin(paths_list[i], "/"); //a proteger..?
		path_cmd = ft_strjoin(cmd->path, cmd->argv[0]); //a proteger..?
		if (access(path_cmd, X_OK) == 0)
		{
  //		  free(path_from_envp);
			free(cmd->path);
			cmd->path = path_cmd;
			free_argv(paths_list);
			return (cmd);
		}
		free(path_cmd);
		i++;
	}
 //   free(path_from_envp);
	ft_printf("%s", cmd->argv[0]); //sortie standard..?
	free_argv(paths_list);
	free_cmd(cmd);
	//ft_putstr_fd("Error\nCommand not found\n", 2);
	perror(" "); // faudrait ajouter nom de la commande pas trouvee ?
	return (NULL);
}

int pipex(int fd1, int fd2, char **av, char **envp)
{
	int		end[2];
	pid_t	cpid;
	t_cmd	*cmd1;
	t_cmd	*cmd2;

	if (pipe(end) == -1)
		return (perror("Error\nPipe fonction"), EXIT_FAILURE);
	cmd1 = split_command(av[2], envp);
//	ft_printf("cmd1 > path: %s -- av0 : %s, av1 : %s\n", cmd1->path, cmd1->argv[0], cmd1->argv[1]);
	cmd2 = split_command(av[3], envp);
//	ft_printf("cmd2 > path: %s -- av0 : %s, av1 : %s\n", cmd2->path, cmd2->argv[0], cmd2->argv[1]);
	if (!cmd1 | !cmd2)
		return (free_cmd(cmd1), free_cmd(cmd2), EXIT_FAILURE);
	//print sortie standard
	cpid = fork();
	if (cpid == -1)
		return (perror("Fork"), EXIT_FAILURE);
	if (cpid == 0)
		child_process(fd1, end, cmd1, envp); 
	// a proteger erreur
	//print dans pipe (?)
	else
		parent_process(end, fd2, cmd2, envp);
	//print dans outfile
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
