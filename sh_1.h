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
# include <sys/types.h>
# include <sys/stat.h>
# include <dirent.h>

typedef	struct		s_var_list
{
	char			*key;
	char			*data;
}					t_var_list;

int					exec(char **argv, t_list *env_list);
t_list				*get_path(char **env);
void				fill_list(char *line, t_list **env_list);
void				print_env(t_list *env_list);
void				print_prompt(t_list *env_list);
char				*good_path(char *name, t_var_list *var);
t_var_list			*good_var(t_list *env_list, char *key);
int					command(char **argv, t_list **env_list);
void				cd(char **argv, t_list *env_list);
int					test_cd(char *path);
char				**env_to_str(t_list *env_list);
void				set_env(char **argv, t_list **env_list);
void				unset_env(char **argv, t_list **env_list);
void				del_list(t_list **env_list, char *key);
void				free_t_var(t_var_list *var);
void				free_env_list(t_list *del);
void				ft_exit(char **argv);
char				*print_error(char *name);

#endif
