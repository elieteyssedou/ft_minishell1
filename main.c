/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteyssed <eteyssed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/10 18:36:17 by eteyssed          #+#    #+#             */
/*   Updated: 2015/03/24 16:39:42 by eteyssed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_1.h"

int		main(int ac, char **av, char **env)
{
	char	*line;
	char	**argv;
	t_list	*env_list;

	(void)ac;
	(void)av;
	env_list = get_path(env);
	while (42)
	{
		print_prompt(env_list);
		get_next_line(0, &line);
		argv = ft_strsplit(ft_strtrim(line), ' ');
		if (!command(argv, &env_list))
			exec(argv, env_list);
	}
	return (0);
}

int		exec(char **argv, t_list *env_list)
{
	pid_t		father;
	t_var_list	*var;
	char		*gp;

	var = good_var(env_list, "PATH");
	gp = good_path(argv[0], var);
	if (gp)
	{
		father = fork();
		if (father > 0)
			waitpid(father, 0, 0);
		else if (father == 0)
		{
			if (execve(gp, argv, env_to_str(env_list)) < 0)
			{
				ft_putstr("exec format error: ");
				ft_putstr(argv[1]);
				ft_putstr("\n");
				exit(2);
			}
		}
	}
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
