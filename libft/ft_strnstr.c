/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteyssed <eteyssed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 15:36:05 by eteyssed          #+#    #+#             */
/*   Updated: 2014/11/06 15:37:29 by eteyssed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s2[j] == '\0')
		return ((char*)s1);
	while (i < n && s1[i])
	{
		if (s1[i] == s2[j])
		{
			while (s1[i] == s2[j] && s1[i] && s2[j] && i < n)
			{
				i++;
				j++;
			}
			if (s2[j] == '\0')
				return ((char*)s1 + i - j);
			i--;
			j = 0;
		}
		i++;
	}
	return (NULL);
}
