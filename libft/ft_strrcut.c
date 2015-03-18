/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrcut.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteyssed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 15:23:28 by eteyssed          #+#    #+#             */
/*   Updated: 2015/03/04 15:23:28 by eteyssed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrcut(char *str, char c)
{
	int		i;
	char	*ret;

	i = 0;
	if (!c)
		return (str);
	i = ft_strlen(str) - 1;
	while (str[i] && str[i] != c)
		i--;
	ret = malloc((sizeof(char) * i));
	ret[i] = 0;
	while (i--)
		ret[i] = str[i];
	return (ret);
}
