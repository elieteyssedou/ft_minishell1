/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 19:55:09 by marvin            #+#    #+#             */
/*   Updated: 2015/02/23 19:55:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_1.h"

char	*good_path(char *name, t_var_list *var)
{
	char			*path;
	DIR				*dirp;
	struct dirent	*dp;

	path = var->data;
	while (path)
	{
		dirp = opendir(ft_strcut(path, ':'));
		if (dirp == NULL)
			break;
		while ((dp = readdir(dirp)) != NULL)
		{
			if (!strcmp(dp->d_name, name))
				return (ft_burger(ft_strcut(path, ':'), '/', name));
		}
		path = ft_strchr(path, ':') + 1;
		closedir(dirp);
	}
	ft_putstr("command not found: ");
	ft_putstr(name);
	ft_putchar('\n');
	return (NULL);
}

t_var_list	*good_var(t_list *env_list, char *key)
{
	t_var_list	*var;
	t_var_list	*no_var;
	t_list		*tmp;
	
	no_var = (t_var_list *)malloc(sizeof(*no_var));
	no_var->key = ft_strdup("NULL");
	no_var->data = ft_strdup("NULL");

	tmp = env_list;
	if (env_list)
		var = tmp->content;
	while (env_list && tmp->next && ft_strcmp(var->key, key))
		tmp = tmp->next, var = tmp->content;
	if (!env_list || !tmp->next)
		return (no_var);
	return (var);
}