/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldinaut <ldinaut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 16:05:55 by ldinaut           #+#    #+#             */
/*   Updated: 2022/03/11 19:26:33 by ldinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*ft_check_slash(t_cmd *cmd)
{
	if (access(cmd->arg_path[0], X_OK) == 0)
		return (cmd->arg_path[0]);
	ft_printf("%s: %s\n", strerror(errno), cmd->arg_path[0]);
	return (NULL);
}

char	*ft_find_check_path(t_cmd *cmd)
{
	int		i;
	char	*temp;

	i = 0;
	if (ft_strchr(cmd->arg_path[0], '/'))
	{
		if (ft_check_slash(cmd) != NULL)
			return (ft_check_slash(cmd));
		return (NULL);
	}
	else
	{
		while (cmd->path_tab[i] != NULL)
		{
			temp = ft_strjoin(cmd->path_tab[i], "/");
			cmd->path = ft_strjoin(temp, cmd->arg_path[0]);
			free(temp);
			if (access(cmd->path, X_OK) == 0)
				return (cmd->path);
			i++;
			free(cmd->path);
		}
		ft_printf("command not found: %s\n", cmd->arg_path[0]);
		return (NULL);
	}
}

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

int	ft_open(t_cmd *cmd, char **argv, int argc)
{
	cmd->infile = open(argv[1], O_RDONLY);
	if (cmd->infile == -1)
	{
		ft_printf("no such file or directory: %s\n", argv[1]);
		return (0);
	}
	cmd->outfile = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
}
