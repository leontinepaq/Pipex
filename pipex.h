/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:39:00 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/02/12 17:41:36 by lpaquatt         ###   ########.fr       */
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


/*free functions*/
void	free_cmd(t_cmd *cmd);
void	free_argv(char **argv);

#endif
