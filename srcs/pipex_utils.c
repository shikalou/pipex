/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldinaut <ldinaut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 17:59:04 by ldinaut           #+#    #+#             */
/*   Updated: 2022/03/05 16:07:19 by ldinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_find_path(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_memcmp(envp[i], "PATH=", 5) == 0)
			return (envp[i] + 5);
		i++;
	}
	return (NULL);
}

void	ft_open(t_command *command, char **argv)
{
	command->infile = open(argv[1], O_RDONLY);
	command->outfile = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
}

char	*ft_check_slash(t_command *command)
{
	if (access(command->arg[0], X_OK) == 0)
		return (command->arg[0]);
	ft_printf("no such file or directory: %s\n", command->arg[0]);
	return (NULL);
}

char	*ft_find_check_path(t_command *command)
{
	int		i;
	char	*temp;

	i = 0;
	if (ft_strchr(command->arg[0], '/'))
	{
		if (ft_check_slash(command) != NULL)
			return (ft_check_slash(command));
		return (NULL);
	}
	else
	{
		while (command->path_tab[i] != NULL)
		{
			temp = ft_strjoin(command->path_tab[i], "/");
			command->path = ft_strjoin(temp, command->arg[0]);
			free(temp);
			if (access(command->path, X_OK) == 0)
				return (command->path);
			i++;
			free(command->path);
		}
		ft_printf("command not found: %s\n", command->arg[0]);
		return (NULL);
	}
}
