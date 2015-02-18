/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteyssed <eteyssed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/18 17:13:29 by eteyssed          #+#    #+#             */
/*   Updated: 2014/11/18 17:13:30 by eteyssed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstadd(t_list **alst, t_list *new)
{
	if (new)
	{
		if (!(*alst))
			*alst = new;
		else
		{
			new->next = *alst;
			*alst = new;
		}
	}
}
