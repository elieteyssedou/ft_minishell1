/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteyssed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/17 18:39:07 by eteyssed          #+#    #+#             */
/*   Updated: 2015/03/17 18:39:08 by eteyssed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_1.h"

static int	test_exist_d(char *name)
{
	DIR				*dirp;

	dirp = opendir(name);
	if (dirp == NULL)
		return (0);
	closedir(dirp);
	return (1);
}

static int	if_cd_1(char **argv, t_var_list *old, t_var_list *pwd)
{
	char	*mem;

	if (!ft_strcmp(argv[1], "..") && !ft_strcmp(pwd->data, "/"))
		old->data = pwd->data;
	else if (!ft_strcmp(argv[1], "..") && !ft_strcmp(pwd->data, "/nfs"))
	{
		old->data = pwd->data;
		pwd->data = ft_strdup("/");
	}
	else if (!ft_strcmp(argv[1], ".."))
	{
		old->data = pwd->data;
		pwd->data = ft_strrcut(pwd->data, '/');
	}
	else if (!ft_strcmp(argv[1], "-"))
	{
		mem = ft_strdup(old->data);
		old->data = pwd->data;
		pwd->data = mem;
	}
	else if (!ft_strcmp(argv[1], "."))
		old->data = pwd->data;
	else
		return (0);
	return (1);
}

static int	if_cd_2(char **argv, t_var_list *old, t_var_list *pwd,
	t_var_list *home)
{
	if (argv[1][0] == '~')
	{
		old->data = pwd->data;
		pwd->data = ft_burger(home->data, '/', &argv[1][1]);
	}
	else if (argv[1][0] == '/' && test_exist_d(argv[1]))
	{
		old->data = pwd->data;
		pwd->data = argv[1];
	}
	else if (!test_cd(argv[1]))
	{
		ft_putstr("cd: no such file or directory: ");
		ft_putstr(argv[1]), ft_putchar('\n');
	}
	else
		return (0);
	return (1);
}

void		cd(char **argv, t_list *env_list)
{
	t_var_list	*old;
	t_var_list	*pwd;
	t_var_list	*home;

	old = good_var(env_list, "OLDPWD");
	pwd = good_var(env_list, "PWD");
	home = good_var(env_list, "HOME");
	if ((!argv[1]) || (!ft_strcmp(argv[1], "HOME")))
	{
		old->data = pwd->data;
		pwd->data = home->data;
	}
	else if (if_cd_1(argv, old, pwd))
		;
	else if (if_cd_2(argv, old, pwd, home))
		;
	else
	{
		old->data = pwd->data;
		pwd->data = ft_burger(pwd->data, '/', argv[1]);
	}
	if ((!pwd->data) || (!ft_strcmp(pwd->data, "")))
		pwd->data = ft_strdup("/");
	chdir(pwd->data);
}

int			test_cd(char *path)
{
	DIR *dirp;

	dirp = opendir(path);
	if (dirp == NULL)
		return (0);
	(void)closedir(dirp);
	return (1);
}
