/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldinaut <ldinaut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 14:09:51 by ldinaut           #+#    #+#             */
/*   Updated: 2022/03/11 15:55:58 by ldinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_free_arg_path(t_cmd *cmd)
{
	int	i;

	i = 0;
	while (cmd->arg_path[i])
	{
		free(cmd->arg_path[i]);
		i++;
	}
	free(cmd->arg_path);
}

void	ft_free_path_tab(t_cmd *cmd)
{
	int	i;

	i = 0;
	while (cmd->path_tab[i])
	{
		free(cmd->path_tab[i]);
		i++;
	}
	free(cmd->path_tab);
}

void	ft_free_struct(t_cmd *cmd)
{
	ft_free_path_tab(cmd);
	ft_free_arg_path(cmd);
	free(cmd);
}