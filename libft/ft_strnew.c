/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteyssed <eteyssed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 17:58:40 by eteyssed          #+#    #+#             */
/*   Updated: 2014/11/12 17:58:41 by eteyssed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char		*str;

	str = (char*)malloc(sizeof(char) * size);
	if (!str)
		return (NULL);
	ft_bzero(str, size + 1);
	return (str);
}
