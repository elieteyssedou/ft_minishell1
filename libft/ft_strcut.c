/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteyssed <eteyssed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 16:21:36 by eteyssed          #+#    #+#             */
/*   Updated: 2015/02/18 16:21:37 by eteyssed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcut(char *str, char c)
{
	int		i;
	char	*ret;

	i = 0;
	if (!c)
		return (str);
	while (str[i] && str[i] != c)
		i++;
	ret = malloc((sizeof(char) * i) + 1);
	ret[i] = 0;
	while (i--)
		ret[i] = str[i];
	return (ret);
}
