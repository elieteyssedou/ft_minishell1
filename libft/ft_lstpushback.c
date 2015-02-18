/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteyssed <eteyssed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 18:58:59 by eteyssed          #+#    #+#             */
/*   Updated: 2015/02/18 18:59:03 by eteyssed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpushback(t_list **start, t_list *new)
{
	t_list		*lst;

	lst = *start;
	if (!(*start))
		*start = new;
	else
	{
		while (lst->next)
			lst = lst->next;
		lst->next = new;
	}
}