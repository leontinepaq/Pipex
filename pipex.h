/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:39:00 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/02/13 11:44:09 by lpaquatt         ###   ########.fr       */
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
# define ERR_NB_ARGS "Error\nWrong nb of args\nFormat: infile cmd1 cmd2 outfile\n"

# define EXIT_SUCCESS 0
# define EXIT_FAILURE 1

typedef struct s_cmd
{
	char	**argv;
	char	*path;
}	t_cmd;


/*split command*/
void	append_paths(char **paths_list);
char	**find_list_paths(char **envp);
t_cmd	*init_cmd(char **argv);
t_cmd	*split_command(char *av, char**envp);

/*free functions*/
void	close_end(int *end);
void	free_cmd(t_cmd *cmd);
void	free_argv(char **argv);

#endif
