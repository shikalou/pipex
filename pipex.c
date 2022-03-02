/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldinaut <ldinaut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 12:41:01 by ldinaut           #+#    #+#             */
/*   Updated: 2022/03/02 19:55:23 by ldinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_first_command(t_command *command, char **argv, char **envp)
{
	int		i;
	char	*path;
	char	**path_tab;

	i = 0;
	path = ft_find_path(envp);
	path_tab = ft_split(path, ':');
	command->arg = ft_split(argv[2], ' ');
	while (path_tab[i] != NULL)
	{
		command->path_name = ft_strjoin(path_tab[i], "/");
		command->path_name = ft_strjoin(command->path_name, command->arg[0]);
		if (access(command->path_name, X_OK) == 0)
		{
			command->arg[0] = ft_strdup(command->path_name);
			dup2(command->fd, 0);
			execve(command->path_name, command->arg, envp);
			exit(1);
		}
		i++;
	}
}

int	main(int argc, char **argv, char **envp)
{
	pid_t		pid;
	t_command	*command;

	(void) argc;
	pid = fork();
	command = malloc(sizeof(t_command));
	command->fd = open(argv[1], O_RDONLY);
	command->fd2 = open(argv[4], O_CREAT);
	ft_first_command(command, argv, envp);
	return (0);
}
