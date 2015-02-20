/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteyssed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 14:00:46 by eteyssed          #+#    #+#             */
/*   Updated: 2015/02/20 14:00:48 by eteyssed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_1.h"

t_list*	get_path(char **env)
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
	//print_env(env_list);
	return (env_list);
}

void	fill_list(char *line, t_list **env_list)
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
