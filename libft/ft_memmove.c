/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteyssed <eteyssed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 12:43:31 by eteyssed          #+#    #+#             */
/*   Updated: 2014/11/07 12:43:33 by eteyssed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const char	*tsrc;
	char		*tdst;

	if (!len)
		return (dst);
	tsrc = (const char *)src;
	tdst = (char *)dst;
	if (tsrc < tdst)
	{
		tdst += len;
		tsrc += len;
		while (len--)
			*--tdst = *--tsrc;
	}
	else
		while (len--)
			*tdst++ = *tsrc++;
	return (dst);
}
