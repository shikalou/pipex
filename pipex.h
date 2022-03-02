/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldinaut <ldinaut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 12:41:15 by ldinaut           #+#    #+#             */
/*   Updated: 2022/03/02 18:31:18 by ldinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>

typedef struct s_command
{
	char	**arg;

	char	*path_name;

	int		fd;
	int		fd2;

}	t_command;

char	**ft_split(char const *s1, char c);

char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_find_path(char **envp);

int		ft_memcmp(const void *s1, const void *s2, size_t n);

size_t	ft_strlen(const char *str);

#endif