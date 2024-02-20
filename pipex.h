/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:39:00 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/02/20 14:01:14 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
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
	int				**pipe_end;
	int				*fd_in;
	int				*fd_out;
	int				*err_out;
	t_cmd			**cmds;
	char			*infile;
	char			*outfile;
}	t_vars;

/*init vars*/
void	init_fd(int **fd, t_vars *vars);
void	init_cmds(t_vars *vars, char **av);
t_vars	*init_vars(int ac, char **av);

/*open fd*/
int		open_file(char *path, int file_type, t_vars *vars);
void	open_fd(t_vars *vars);

/*free vars*/
void	free_argv(char **argv);
void	free_cmd(t_cmd *cmd);
void	free_cmds(t_cmd **cmds, unsigned int nb_cmds);
void	close_fds(int	*fd, unsigned int nb_cmds);
void	free_vars(t_vars *vars);

#endif
