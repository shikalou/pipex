#include "pipex.h"

void	ft_exec_two(char **argv, char **envp, t_command *command, int pipefd[2])
{
	int		i;
	pid_t	pid;

	i = 0;
	pid = fork();
	if (pid < 0)
		exit (1);
	command->arg = ft_split(argv[3], ' ');
	if (pid == 0)
	{
		while (command->path_tab[i] != NULL)
		{
			command->path_name = ft_strjoin(command->path_tab[i], "/");
			command->path_name = ft_strjoin(command->path_name, command->arg[0]);
			if (access(command->path_name, X_OK) == 0)
			{
				command->arg[0] = ft_strdup(command->path_name);
				dup2(pipefd[0], 0);
				dup2(command->outfile, 1);
				execve(command->path_name, command->arg, envp);
				exit(1);
			}
			i++;
		}
	}
}

void	ft_exec_one(t_command *command, char **argv, char **envp, int pipefd[2])
{
	int		i;
	pid_t	pid;

	i = 0;
	pid = fork();
	if (pid < 0)
		exit (1);
	command->arg = ft_split(argv[2], ' ');
	if (pid == 0)
	{
		while (command->path_tab[i] != NULL)
		{
			command->path_name = ft_strjoin(command->path_tab[i], "/");
			command->path_name = ft_strjoin(command->path_name, command->arg[0]);
			if (access(command->path_name, X_OK) == 0)
			{
				command->arg[0] = ft_strdup(command->path_name);
				close(pipefd[0]);
				dup2(command->infile, 0);
				dup2(pipefd[1], 1);
				execve(command->path_name, command->arg, envp);
				exit(1);
			}
			i++;
		}
	}
}

int	main(int argc, char **argv, char **envp)
{
	int			pipefd[2];
	t_command	*command;
	char		*path;

	(void) argc;
	command = malloc(sizeof(t_command));
	path = ft_find_path(envp);
	command->path_tab = ft_split(path, ':');
	command->infile = open(argv[1], O_RDONLY);
	command->outfile = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (pipe(pipefd) < 0)
		return (1);
	ft_exec_one(command, argv, envp, pipefd);
	close(command->infile);
	close(pipefd[1]);
	ft_exec_two(argv, envp, command, pipefd);
	close(command->outfile);
	close(pipefd[0]);
	wait(NULL);
	wait(NULL);
	return (0);
}