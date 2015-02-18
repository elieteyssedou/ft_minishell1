/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteyssed <eteyssed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 18:10:01 by eteyssed          #+#    #+#             */
/*   Updated: 2014/11/13 18:10:02 by eteyssed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
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
		fstr[i] = f(s[i]);
		i++;
	}
	fstr[i] = 0;
	return (fstr);
}
