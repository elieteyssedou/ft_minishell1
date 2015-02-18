/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsmartpushback.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteyssed <eteyssed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 18:56:39 by eteyssed          #+#    #+#             */
/*   Updated: 2015/02/18 18:56:41 by eteyssed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstsmartpushback(t_list **start, t_list *new)
{
	static t_list	*memstart = NULL;
	static t_list	*memend = NULL;

	if (memstart && *start == memstart)
	{
		memend->next = new;
		memend = new;
	}
	else
	{
		ft_lstpushback(start, new);
		memstart = *start;
		memend = new;
	}
}
