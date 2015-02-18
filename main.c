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

int main(int ac, char **av, char **env)
{
	char *line;

	//while (*env)
	// 	printf("%s\n", *env++);
	get_path(env);
	while (42)
	{
		ft_putstr("$>");
		get_next_line(0, &line);
		exec(ft_strsplit(ft_strtrim(line), ' '));
	}
}

int exec(char **argv)
{
	pid_t father;

	father = fork();
	if (father > 0)
		waitpid(father, 0, 0);
	else if (father == 0)
		execve(argv[0], argv, NULL);
	return (0);
}

void	get_path(char **env)
{
	int i;
	t_list *env_list;

	i = 0;
	env_list = NULL;
	while (env[i])
	{
		fill_list(env[i], &env_list);
		i++;
	}
	print_env(env_list);
}

t_list	fill_list(char *line, t_list **env_list)
{
	t_var_list	var;

	var.key = ft_strcut(line, '=');
	var.data = ft_strdup(ft_strchr(line, '=') + 1);
	ft_lstsmartpushback(env_list,
		ft_lstnew(&var, (sizeof(t_var_list))));
}

void	print_env(t_list *env_list)
{
	t_var_list *var;

	while (env_list)
	{
		var = env_list->content;
		ft_putstr(var->key);
		ft_putstr("=");
		ft_putstr(var->data);
		ft_putstr("\n");
		env_list = env_list->next;
	}
}