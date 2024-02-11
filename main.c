#include "pipex.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int    child_process(int fd, int* end, t_cmd *cmd, char**envp)
{
    close(end[0]);
    dup2(fd, STDIN_FILENO);
    dup2(end[1], STDOUT_FILENO);
    close(end[1]);
    close(fd);
    execve(cmd->path,cmd->argv, envp);
    return (EXIT_SUCCESS);
}

int    parent_process(int *end, int fd, t_cmd *cmd, char**envp)
{
    close(end[1]);
    dup2(end[0], STDIN_FILENO);
    dup2(fd, STDOUT_FILENO);
    close(end[1]);
    close(fd);
    execve(cmd->path,cmd->argv, envp);
    return (EXIT_SUCCESS);
}

t_cmd   *split_command(char *av, char**envp)
{
    t_cmd   *cmd;
    char    *path_from_envp;
    char    **paths_list;
    int     i;
    char    *path_cmd;

    cmd = malloc(sizeof(t_cmd));
    if (!cmd)
        return (perror(ERR_MALLOC), NULL);
    path_from_envp = "/usr/bin";
    (void) envp;
//  path_from_envp = find_list_paths(envp);
    paths_list = ft_split(path_from_envp, ' ');
    if (!paths_list)
        return (NULL); //perror
//        return (free(path_from_envp), free(cmd), NULL);
    cmd->argv = ft_split(av, ' ');
    if (!cmd)
        return (free(paths_list), NULL); //perror
//        return (free(path_from_envp), free(paths_list), free(cmd), NULL);
    i = 0;
    while (paths_list[i])
    {
        cmd->path = ft_strjoin(paths_list[i], "/");
        path_cmd = ft_strjoin(path_cmd, cmd[0]);
        if (access(path_cmd, X_OK) == 0)
        {
  //          free(path_from_envp);
            free(paths_list);
            return (cmd);
        }
        free(path_cmd);
        i++;
    }
 //   free(path_from_envp);
    free(paths_list);
    free(cmd);
    //perror -> invalid path
    return (NULL);
}

int pipex(int fd1, int fd2, char **av, char **envp)
{
    int     end[2];
    pid_t   cpid;
    t_cmd   *cmd1;
    t_cmd   *cmd2;

    pipe(end);
    cmd1 = split_command(av[2], envp);
    cmd2 = split_command(av[3], envp);
    if (!cmd1 | !cmd2)
        return (EXIT_FAILURE);
    cpid = fork();
    if (cpid == -1)
        return (perror("Fork: \n"), EXIT_FAILURE);
    if (cpid == 0)
        child_process(fd1, end, cmd1, envp);
    else
        parent_process(end, fd2, cmd2, envp);
    return (EXIT_SUCCESS);
}

int main(int ac, char **av, char **envp)
{
    int fd1;
    int fd2;

    if (ac != 5)
    {
        perror("Error\nIncorrect number of arguments\nRequired format : infile cmd1 cmd2 outfile\n");
        return (EXIT_FAILURE);
    }   
    fd1 = open(av[1], O_RDONLY);
    fd2 = open(av[4], O_CREAT | O_RDWR | O_TRUNC, 0644); // pk 644 ? (User RW group R other R)
    if (fd1 < 0 || fd2 < 0)
        return (EXIT_FAILURE);
    if (pipex(fd1, fd2, av, envp) == EXIT_FAILURE)
        return (close(fd1), close(fd2), EXIT_FAILURE);
    close(fd1);
    clode(fd2);
    return (EXIT_SUCCESS);
}