/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteyssed <eteyssed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 19:36:21 by eteyssed          #+#    #+#             */
/*   Updated: 2014/11/06 19:36:30 by eteyssed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	ca;
	int		i;

	i = 0;
	ca = (char)c;
	while (s[i] != '\0')
	{
		if (ca == s[i])
			return ((char*)&s[i]);
		i++;
	}
	if (ca == s[i])
		return ((char*)&s[i]);
	return (NULL);
}
