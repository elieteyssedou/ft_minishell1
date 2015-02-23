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

