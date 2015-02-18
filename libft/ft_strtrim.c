/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteyssed <eteyssed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 19:26:36 by eteyssed          #+#    #+#             */
/*   Updated: 2014/11/12 19:26:37 by eteyssed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_sp(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

char				*ft_strtrim(const char *s)
{
	char			*dst;
	size_t			i;
	size_t			e;

	if (!s)
		return (NULL);
	i = 0;
	while (ft_sp(*s++))
		i++;
	s -= i + 1;
	e = ft_strlen(s) - 1;
	if (!*s || e == i - 1)
		return (dst = ft_strnew(1));
	if (i != (e + 1))
		while (ft_sp(s[e]))
			e--;
	dst = ft_strsub(s, i, (e - i + 1));
	return (dst);
}
