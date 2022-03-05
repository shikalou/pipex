/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldinaut <ldinaut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 12:41:15 by ldinaut           #+#    #+#             */
/*   Updated: 2022/03/05 18:54:10 by ldinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include "../ft_printf/ft_printf.h"

typedef struct s_command
{
	char	**arg;
	char	**path_tab;

	char	*path;

	int		infile;
	int		outfile;

}	t_command;

char	**ft_split(char const *s1, char c);

char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_find_path(char **envp);
char	*ft_find_check_path(t_command *command);
char	*ft_strchr(const char *s, int c);
char	*ft_check_slash(t_command *command);

int		ft_memcmp(const void *s1, const void *s2, size_t n);

void	ft_open(t_command *command, char **argv);
void	ft_free_struct(t_command *command);
void	ft_free_path_tab(t_command *command);
void	ft_free_arg(t_command *command);
void	ft_close(t_command *command, int pipefd[2], int i);

size_t	ft_strlen(const char *str);

#endif