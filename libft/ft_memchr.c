/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteyssed <eteyssed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 15:24:19 by eteyssed          #+#    #+#             */
/*   Updated: 2014/11/07 15:24:19 by eteyssed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	ca;
	size_t			i;

	i = 0;
	ca = (unsigned char)c;
	str = (unsigned char *)s;
	while (i != n && str[i] != ca && str)
		i++;
	if (i == n)
		return (NULL);
	return ((void *)s + i);
}
