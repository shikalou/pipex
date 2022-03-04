/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldinaut <ldinaut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 14:28:53 by ldinaut           #+#    #+#             */
/*   Updated: 2022/03/04 15:01:09 by ldinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_arg(t_command *command)
{
	int	i;

	i = 0;
	while (command->arg[i])
	{
		free(command->arg[i]);
		i++;
	}
	free(command->arg);
}

void	ft_free_path_tab(t_command *command)
{
	int	i;

	i = 0;
	while (command->path_tab[i])
	{
		free(command->path_tab[i]);
		i++;
	}
	free(command->path_tab);
}

void	ft_free_struct(t_command *command)
{
	ft_free_path_tab(command);
	ft_free_arg(command);
	free(command);
}
