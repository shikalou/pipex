/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldinaut <ldinaut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 15:00:35 by ldinaut           #+#    #+#             */
/*   Updated: 2022/03/07 17:39:34 by ldinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int argc, char **argv, char **envp)
{
	char	*path;
	char 	**path_tab;
	(void)argc;

	path = ft_find_path(envp);
	path_tab = ft_split(path, ':');
}