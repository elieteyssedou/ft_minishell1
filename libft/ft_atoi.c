/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteyssed <eteyssed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 16:28:58 by eteyssed          #+#    #+#             */
/*   Updated: 2014/11/06 16:29:01 by eteyssed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	int		ret;
	char	si;

	ret = 0;
	si = 1;
	while (*str == ' ' || *str == '\t' || *str == '\r'
			|| *str == '\v' || *str == '\n' || *str == '\f')
		str++;
	if (*str == '-' || *str == '+')
	{
		si = (*str == '-' ? -1 : 1);
		str++;
	}
	while (ft_isdigit(*str))
	{
		ret = ret * 10 + si * (*str - '0');
		str++;
	}
	return (ret);
}
