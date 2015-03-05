/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteyssed <eteyssed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 15:27:52 by eteyssed          #+#    #+#             */
/*   Updated: 2015/02/18 15:27:53 by eteyssed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_1_H
# define SH_1_H

# include "libft/libft.h"
# include "libft/get_next_line.h"
# include <sys/wait.h>
# include <dirent.h>
# include <stdio.h> //a enlever

typedef	struct		s_var_list
{
	char			*key;
	char			*data;
}					t_var_list;

int			exec(char **argv, t_list *env_list);
t_list*		get_path(char **env);
void		fill_list(char *line, t_list **env_list);
void		print_env(t_list *env_list);
void		print_prompt(t_list *env_list);
char*		good_path(char *name, t_var_list *var);
t_var_list	*good_var(t_list *env_list, char *key);
int			command(char **argv, t_list *env_list);
void		cd(char **argv, t_list *env_list);
int			test_cd(char *path);

#endif