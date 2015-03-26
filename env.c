/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteyssed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/25 21:22:46 by eteyssed          #+#    #+#             */
/*   Updated: 2015/03/25 21:22:47 by eteyssed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_1.h"

t_var_list	*good_var(t_list *env_list, char *key)
{
	t_var_list			*var;
	t_list				*tmp;
	static t_var_list	*no_var;

	if (!(no_var = (t_var_list *)malloc(sizeof(*no_var))))
		return (NULL);
	no_var->key = NULL;
	no_var->data = NULL;
	tmp = env_list;
	if (env_list)
		var = tmp->content;
	while (env_list && tmp && ft_strcmp(var->key, key))
	{
		tmp = tmp->next;
		if (tmp)
			var = tmp->content;
	}
	if (!env_list || !tmp)
		return (no_var);
	return (var);
}

void		del_list(t_list **env_list, char *key)
{
	t_var_list	*var;
	t_list		*tmp;
	t_list		*del;

	tmp = *env_list;
	var = tmp->content;
	if (!ft_strcmp(var->key, key))
	{
		*env_list = tmp->next;
		free_env_list(tmp);
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
		return ;
	del = tmp->next;
	tmp->next = del->next;
	free_env_list(del);
}

void		free_env_list(t_list *del)
{
	free(del->content);
	free(del);
}
