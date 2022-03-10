/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldinaut <ldinaut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 15:00:35 by ldinaut           #+#    #+#             */
/*   Updated: 2022/03/10 18:53:49 by ldinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_exec_last(t_cmd *cmd, char *argv, char **envp)
{
	pid_t	pid;

	cmd->arg_path = ft_split(argv, ' ');
	pid = fork();
	if (pid < 0)
		exit(1);

	if (pid == 0)
	{
		if (ft_find_check_path(cmd) != NULL)
		{
			cmd->arg_path[0] = ft_strdup(cmd->path);
			dup2(cmd->pipefd[0], 0);
			dup2(cmd->outfile, 1);
			execve(cmd->path, cmd->arg_path, envp);

		}
		exit(1);
	}
}

void	ft_exec_middle(t_cmd *cmd, char *argv, char **envp)
{
	pid_t	pid;

	cmd->arg_path = ft_split(argv, ' ');
	cmd->fd_temp =	cmd->pipefd[0];
	pipe(cmd->pipefd);
	pid = fork();
	if (pid < 0)
		exit(1);
	if (pid == 0)
	{
		if (ft_find_check_path(cmd) != NULL)
		{
			cmd->arg_path[0] = ft_strdup(cmd->path);
			dup2(cmd->fd_temp, 0);
			close(cmd->pipefd[0]);
			dup2(cmd->pipefd[1], 1);
			execve(cmd->path, cmd->arg_path, envp);
		}
		exit(1);
	}
	close(cmd->pipefd[1]);
	close(cmd->fd_temp);
}

void	ft_exec_one(t_cmd *cmd, char **argv, char **envp)
{
	pid_t	pid;

	cmd->arg_path = ft_split(argv[2], ' ');
	pipe(cmd->pipefd);
	pid = fork();
	if (pid < 0)
		exit(1);
	if (pid == 0)
	{
		if (ft_find_check_path(cmd) != NULL)
		{
			cmd->arg_path[0] = ft_strdup(cmd->path);
			close(cmd->pipefd[0]);
			dup2(cmd->infile, 0);
			dup2(cmd->pipefd[1], 1);
			execve(cmd->path, cmd->arg_path, envp);

		}
		exit(1);
	}
	close(cmd->pipefd[1]);
	close(cmd->infile);
}

int	main(int argc, char **argv, char **envp)
{
	char	*path;
	t_cmd 	*cmd;
	int		i;

	if (argc > 4)
	{
		i = 0;
		cmd = malloc(sizeof(t_cmd));
		path = ft_find_path(envp);
		cmd->path_tab = ft_split(path, ':');
		ft_open(cmd, argv, argc);

		ft_exec_one(cmd, argv, envp);

		while (i < argc - 5)
		{
			ft_exec_middle(cmd, argv[i + 3], envp);
			i++;
		}
		ft_exec_last(cmd, argv[i + 3], envp);
		wait(NULL);
		wait(NULL);
		wait(NULL);
		return (0);
	}
	ft_printf("[infile] [cmd1] [cmd2] ... [cmdn] [outfile]\n");
	return (1);
}