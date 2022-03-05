/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldinaut <ldinaut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 15:11:09 by ldinaut           #+#    #+#             */
/*   Updated: 2022/03/05 16:09:32 by ldinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		if (ft_find_check_path(command) != NULL)
		{
			command->arg[0] = ft_strdup(command->path);
			dup2(pipefd[0], 0);
			dup2(command->outfile, 1);
			execve(command->path, command->arg, envp);
			exit(1);
		}
		ft_free_struct(command);
		exit(1);
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
		if (ft_find_check_path(command) != NULL)
		{
			command->arg[0] = ft_strdup(command->path);
			close(pipefd[0]);
			dup2(command->infile, 0);
			dup2(pipefd[1], 1);
			execve(command->path, command->arg, envp);
			exit(1);
		}
		ft_free_struct(command);
		exit(1);
	}
	ft_free_arg(command);
}

int	main(int argc, char **argv, char **envp)
{
	int			pipefd[2];
	t_command	*command;
	char		*path;

	if (argc == 5)
	{
		command = malloc(sizeof(t_command));
		path = ft_find_path(envp);
		command->path_tab = ft_split(path, ':');
		ft_open(command, argv);
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
		ft_free_struct(command);
		return (0);
	}
	ft_printf("[infile] [cmd1] [cmd2] [outfile]\n");
	return (1);
}
