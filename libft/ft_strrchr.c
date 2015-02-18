/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteyssed <eteyssed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 20:05:45 by eteyssed          #+#    #+#             */
/*   Updated: 2014/11/06 20:05:46 by eteyssed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	ca;
	int		i;

	i = 0;
	ca = (char)c;
	while (s[i] != '\0')
		i++;
	while (i != 0)
	{
		if (ca == s[i])
			return ((char*)&s[i]);
		i--;
	}
	if (ca == s[i])
		return ((char*)&s[i]);
	return (NULL);
}
