/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 19:55:09 by marvin            #+#    #+#             */
/*   Updated: 2015/03/25 21:20:11 by eteyssed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_1.h"

static int	test_exist(char *name)
{
	DIR				*dirp;
	struct dirent	*dp;

	dirp = opendir(ft_strrcut(name, '/'));
	if (dirp == NULL)
		return (0);
	while ((dp = readdir(dirp)) != NULL)
	{
		if (!strcmp(dp->d_name, ft_strrchr(name, '/') + 1))
			return (1);
	}
	closedir(dirp);
	return (0);
}

char		*print_error(char *name)
{
	struct stat	stat_buff;

	lstat(name, &stat_buff);
	if (name[0] != '/' && name[0] != '.')
	{
		ft_putstr("command not found: ");
		ft_putstr(name);
		ft_putchar('\n');
	}
	else if (!test_exist(name))
	{
		ft_putstr("no such file or directory: ");
		ft_putstr(name);
		ft_putchar('\n');
	}
	else if (!(stat_buff.st_mode & 010) | S_ISDIR(stat_buff.st_mode))
	{
		ft_putstr("permission denied: ");
		ft_putstr(name);
		ft_putchar('\n');
	}
	else
		return (name);
	return (NULL);
}

static char	*print_error_path(char *path, char *name)
{
	struct stat	stat_buff;

	name = ft_burger(ft_strcut(path, ':'), '/', name);
	lstat(name, &stat_buff);
	if (!(stat_buff.st_mode & 010) | S_ISDIR(stat_buff.st_mode))
	{
		ft_putstr("permission denied: ");
		ft_putstr(name);
		ft_putchar('\n');
	}
	else
		return (name);
	return (NULL);
}

static void	good_path_bis(char **path)
{
	if (ft_strchr(*path, ':'))
		*path = ft_strchr(*path, ':') + 1;
	else
		*path = NULL;
}

char		*good_path(char *name, t_var_list *var)
{
	char			*path;
	DIR				*dirp;
	struct dirent	*dp;

	if (var->data)
	{
		path = var->data;
		while (path)
		{
			dirp = opendir(ft_strcut(path, ':'));
			if (dirp == NULL)
				break ;
			while ((dp = readdir(dirp)) != NULL)
			{
				if (!ft_strcmp(dp->d_name, name))
				{
					if (!print_error_path(path, name))
						return (NULL);
					return (ft_burger(ft_strcut(path, ':'), '/', name));
				}
			}
			good_path_bis(&path), closedir(dirp);
		}
	}
	return (print_error(name));
}
