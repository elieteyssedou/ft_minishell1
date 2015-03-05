/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteyssed <eteyssed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/10 18:36:17 by eteyssed          #+#    #+#             */
/*   Updated: 2015/02/10 18:36:18 by eteyssed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_1.h"

int 	main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	char *line;
	char **argv;
	t_list *env_list;

	env_list = get_path(env);
	while (42) //ou while(env_list) si on ne veux pas lancer le term avec env -i
	{
		print_prompt(env_list);
		get_next_line(0, &line);
		argv = ft_strsplit(ft_strtrim(line), ' ');
		if (!command(argv, env_list))
			exec(argv, env_list);
	}
	return (0);
}

int		command(char **argv, t_list *env_list)
{
	if (!ft_strcmp(argv[0], "cd"))
		cd(argv, env_list);
	else if (!ft_strcmp(argv[0], "env"))
		print_env(env_list);
	else
		return (0);
	return (1);
}

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
	else if (!test_cd(ft_strcut(argv[1], '/')))
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
	struct dirent *dp;

	dirp = opendir(".");
	if (dirp == NULL)
	        return (0);
	while ((dp = readdir(dirp)) != NULL)
	{
		if (!ft_strcmp(dp->d_name, path))
		{
			(void)closedir(dirp);
			return (1);
		}
	}
	(void)closedir(dirp);
	return (0);
}

int 	exec(char **argv, t_list *env_list)
{
	pid_t father;
	t_var_list	*var;
		
	var = good_var(env_list, "PATH");
	
	father = fork();
	if (father > 0)
		waitpid(father, 0, 0);
	else if (father == 0)
		execve(good_path(argv[0], var), argv, NULL);
	return (0);
}

void	print_prompt(t_list *env_list)
{
	t_var_list *var;

	var = good_var(env_list, "USER");
	ft_putstr(var->data);
	ft_putstr(" on ");
	var = good_var(env_list, "PWD");
	ft_putstr("\033[1;35m"), ft_putstr(ft_strrchr(var->data, '/'));
	ft_putstr("\033[0m");
	ft_putstr(" $> ");
}