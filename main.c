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
	ac = ac;
	av = av;
	char *line;
	t_list *env_list;

	env_list = get_path(env);
	while (42)
	{
		ft_putstr("$>");
		print_prompt(env_list);
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

void	print_prompt(t_list *env_list)
{
	
}