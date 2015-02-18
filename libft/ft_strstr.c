/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteyssed <eteyssed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 15:36:14 by eteyssed          #+#    #+#             */
/*   Updated: 2014/11/06 15:37:33 by eteyssed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strstr(const char *s1, const char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (s2[j] == '\0')
		return ((char*)s1);
	while (s1[i] != '\0')
	{
		if (s1[i] == s2[0])
		{
			while ((s1[i] == s2[j]) && s1[i] && s2[j])
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
