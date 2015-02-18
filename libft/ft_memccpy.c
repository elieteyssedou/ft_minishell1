/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteyssed <eteyssed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 11:49:04 by eteyssed          #+#    #+#             */
/*   Updated: 2014/11/07 11:49:05 by eteyssed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	const char	*temp;
	char		*tdst;
	size_t		i;
	int			a;

	a = 0;
	i = -1;
	temp = src;
	tdst = dst;
	while ((i + 1) != n && temp[i] != (const char)c)
	{
		i++;
		tdst[i] = temp[i];
		if (temp[i] == (const char)c)
			a = 1;
	}
	if (a == 0)
		return (NULL);
	return (tdst + i + 1);
}
