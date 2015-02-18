/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteyssed <eteyssed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 18:40:56 by eteyssed          #+#    #+#             */
/*   Updated: 2014/11/12 18:40:57 by eteyssed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*zone;
	char	*retour;
	size_t	size;

	if (s1 && s2)
		size = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(zone = malloc(size * sizeof(zone))))
		return (NULL);
	retour = zone;
	if (s1 && s2)
	{
		while (*s1)
			*zone++ = *s1++;
		while (*s2)
			*zone++ = *s2++;
	}
	*zone = '\0';
	return (retour);
}
