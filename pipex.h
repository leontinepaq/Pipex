#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"

# define ERR_MALLOC "Error\nProblem with memory allocation (malloc function)\n"

# define EXIT_SUCCESS 0
# define EXIT_FAILURE 1

typedef struct s_cmd
{
    char    *path;
    char    **argv;
}	t_cmd;



#endif
