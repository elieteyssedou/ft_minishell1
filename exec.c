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
	no_var->key = NULL;
	no_var->data = NULL;

	tmp = env_list;
	if (env_list)
		var = tmp->content;
	while (tmp && ft_strcmp(var->key, key))
	{
		tmp = tmp->next;
		if (tmp)
			var = tmp->content;
	}
	if (!env_list || !tmp)
		return (no_var);
	return (var);
}

void	del_list(t_list *env_list, char *key)
{
	t_var_list	*var;
	t_list		*tmp;
	t_list		*del;

	tmp = env_list;
	var = tmp->content;
	if (!ft_strcmp(var->key, key))
		{
			env_list = env_list->next;
			free_env_list(tmp);
			print_env(env_list);
			return ;
		}
	while (tmp->next && ft_strcmp(var->key, key))
	{
		var = tmp->next->content;
		if (ft_strcmp(var->key, key))
			tmp = tmp->next;
		else
			break ;
	}
	if (!tmp->next)
	{
		return ;
	}
	del = tmp->next;
	tmp->next = del->next;
	free_env_list(del);
	print_env(env_list);
}

void	free_env_list(t_list *del)
{
	free(del->content);
	free(del->next);
	free(del);
}