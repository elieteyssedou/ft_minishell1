/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteyssed <eteyssed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 21:18:07 by eteyssed          #+#    #+#             */
/*   Updated: 2014/11/12 21:18:08 by eteyssed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;

	str = ft_strnew((len) + 1);
	if (!str)
		return (NULL);
	if (s)
	{
		while (*s && start--)
			s++;
		str = ft_strncat(str, s, len);
	}
	return (str);
}
