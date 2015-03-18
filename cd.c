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

void	cd(char **argv, t_list *env_list)
{
	t_var_list	*old;
	t_var_list	*pwd;
	t_var_list	*home;
	char		*mem;

	old = good_var(env_list, "OLDPWD");
	pwd = good_var(env_list, "PWD");
	home = good_var(env_list, "HOME");
	if (!argv[1])
	{
		old->data = pwd->data;
		pwd->data = home->data;
	}
	else if (!ft_strcmp(argv[1], "..") && !ft_strcmp(pwd->data, "/"))
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
	else if (argv[1][0] == '~')
	{
		old->data = pwd->data;
		pwd->data = ft_burger(home->data, '/', &argv[1][1]);
	}
	else if (!test_cd(argv[1]))
	{
		ft_putstr("cd: no such file or directory: ");
		ft_putstr(argv[1]), ft_putchar('\n');
	}
	else
	{
		old->data = pwd->data;
		pwd->data = ft_burger(pwd->data, '/', argv[1]);
	}
	chdir(pwd->data);
}

int		test_cd(char *path)
{
	DIR *dirp;

	dirp = opendir(path);
	if (dirp == NULL)
	        return (0);
	(void)closedir(dirp);
	return (1);
}
