/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteyssed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/25 19:45:39 by eteyssed          #+#    #+#             */
/*   Updated: 2015/03/25 19:45:40 by eteyssed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_1.h"

int		command(char **argv, t_list **env_list)
{
	if (!argv[0])
		return (1);
	else if (!ft_strcmp(argv[0], "cd"))
		cd(argv, *env_list);
	else if (!ft_strcmp(argv[0], "env"))
		print_env(*env_list);
	else if (!ft_strcmp(argv[0], "setenv"))
		set_env(argv, env_list);
	else if (!ft_strcmp(argv[0], "unsetenv"))
		unset_env(argv, env_list);
	else if (!ft_strcmp(argv[0], "exit"))
		ft_exit(argv);
	else
		return (0);
	return (1);
}

void	set_env(char **argv, t_list **env_list)
{
	t_var_list	*var;

	if (argv[3])
		ft_putstr("setenv: Too many arguments.\n");
	if (!argv[1])
		print_env(*env_list);
	else if (argv[1])
	{
		var = good_var(*env_list, argv[1]);
		if (!var->key)
		{
			var->key = argv[1];
			var->data = argv[2];
			ft_lstpushback(env_list,
			ft_lstnew(var, (sizeof(t_var_list))));
		}
		else
			var->data = argv[2];
	}
}

void	unset_env(char **argv, t_list **env_list)
{
	int i;

	i = 1;
	if (!argv[1])
		ft_putstr("unsetenv: Too few arguments.\n");
	else
	{
		while (argv[i])
		{
			del_list(env_list, argv[i]);
			i++;
		}
	}
}

void	ft_exit(char **argv)
{
	if (argv[1])
		exit(ft_atoi(argv[1]));
	exit(0);
}
