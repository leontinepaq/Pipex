/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:39:00 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/02/21 18:34:02 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>

# define ERR_MALLOC "Error\nProblem with memory allocation (malloc function)\n"

# define READ 0
# define WRITE 1

# define INFILE 0
# define OUTFILE 1

typedef struct s_cmd
{
	char	**argv;
	char	*path;
	char	*cmd;
}	t_cmd;

typedef struct s_vars
{
	unsigned int	nb_cmds;
	unsigned int	index;
	int				*fd_in;
	int				*fd_out;
	int				*fd_err_in;
	int				*fd_err_out;
	t_cmd			**cmd;
	char			*infile;
	char			*outfile;
	pid_t			*cpid;
	char			**paths_list;
	char			**envp;
}	t_vars;

/*init vars*/
void	init_fd(int **fd, t_vars *vars);
void	init_cmds(t_vars *vars, char **av);
t_vars	*malloc_vars(void);
t_vars	*init_vars(int ac, char **av, char **envp);

/* init list paths*/
void	append_paths(char **paths_list);
void	init_paths_list(t_vars *vars, char **envp);

/*open pipes*/
int		open_file(char *path, int file_type, t_vars *vars);
void	open_fd_in_out(t_vars *vars);
void	open_fd_err_in_out(t_vars *vars);
void	open_pipes(t_vars *vars);

/*child process*/
void	exec_cmd(t_cmd *cmd, t_vars *vars);
void	dup_filenos(t_vars *vars);
void	child_process(t_vars *vars);

/*check cmd*/
int		access_via_envt(t_cmd *cmd, t_vars *vars);
int		is_path(char *str);
void	find_cmd_path(t_cmd *cmd, t_vars *vars);
void	check_exec(t_cmd *cmd, t_vars *vars);
void	check_cmd(t_cmd *cmd, t_vars *vars);

/*parent process*/
int	wait_for_childs(t_vars *vars);
void	put_child_errors(t_vars *vars);
void	parent_process(t_vars *vars);

/*free vars*/
void	free_cmd(t_cmd *cmd);
void	free_cmds(t_cmd **cmds, unsigned int nb_cmds);
void	close_fds(int *fd, unsigned int nb_cmds);
void	free_fds(int *fd, unsigned int nb_cmds);
void	free_vars(t_vars *vars);

#endif
