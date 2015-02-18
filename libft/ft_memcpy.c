/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteyssed <eteyssed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 11:32:08 by eteyssed          #+#    #+#             */
/*   Updated: 2014/11/07 11:32:08 by eteyssed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*strdst;
	const unsigned char	*strsrc;

	strdst = (unsigned char*)dst;
	strsrc = (const unsigned char*)src;
	while (n--)
		*strdst++ = *strsrc++;
	return (dst);
}
