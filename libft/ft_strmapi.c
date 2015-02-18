/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteyssed <eteyssed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 19:22:30 by eteyssed          #+#    #+#             */
/*   Updated: 2014/11/13 19:22:31 by eteyssed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*fstr;

	i = 0;
	if (!(s && f))
		return (NULL);
	if (!(fstr = malloc((sizeof(fstr) * ft_strlen(s) + 1))))
		fstr = NULL;
	while (s[i] && s[i] != 0)
	{
		fstr[i] = f(i, s[i]);
		i++;
	}
	fstr[i] = 0;
	return (fstr);
}
