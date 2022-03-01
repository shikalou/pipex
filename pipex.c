/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldinaut <ldinaut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 12:41:01 by ldinaut           #+#    #+#             */
/*   Updated: 2022/03/01 19:28:16 by ldinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	int			i;
	char		*dest;

	i = 0;
	dest = malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (!dest)
		return (NULL);
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int			i;
	int			j;
	int			k;
	char		*dest;

	i = 0;
	j = 0;
	k = (ft_strlen(s1) + ft_strlen(s2));
	dest = malloc(sizeof(char) * (k + 1));
	if (!dest)
		return (NULL);
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		dest[i] = s2[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	return (0);
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

int	main(int argc, char **argv, char **envp)
{
	char *path;
	char	**split;
	char	**arg;
	char *path_name;
	int	i;
	int fd;

	(void) argc;
	i = 0;
	fd = open(argv[1], O_RDONLY);
	path = ft_find_path(envp);
	split = ft_split(path, ':');
	while (split[i] != NULL)
	{
		path_name = ft_strjoin(split[i], "/");
		path_name = ft_strjoin(path_name, argv[2]);
		if (access(path_name, X_OK) == 0)
		{
			arg = malloc(sizeof(char *) * 2);
			arg[0] = ft_strdup(path_name);
			arg[1] = NULL;
			dup2(fd, 0);
			execve(path_name, arg, envp);
			exit(1);
		}
		i++;
	}
	return (0);
}
