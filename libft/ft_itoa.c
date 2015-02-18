/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteyssed <eteyssed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 21:39:56 by eteyssed          #+#    #+#             */
/*   Updated: 2014/11/12 21:39:57 by eteyssed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		cbi(int n)
{
	int i;

	i = 0;
	while (n /= 10)
		i++;
	return (i);
}

int		power(int n)
{
	int	y;
	int	m;

	y = 1;
	m = 1;
	while (m <= n)
	{
		y *= 10;
		m++;
	}
	return (y);
}

char	*ft_itoa(int n)
{
	char	*nbr;
	char	*ret;
	int		size;
	int		i;
	int		t;

	i = 0;
	size = cbi(n);
	if (!(nbr = malloc(sizeof(nbr) * (size + (n < 0 ? 1 : 0) + 1))))
		return (NULL);
	ret = nbr;
	if (n == -2147483648)
		return (ft_strcpy(nbr, "-2147483648"));
	if (n < 0)
		*nbr++ = '-';
	if (n < 0)
		n = -n;
	while (i != size + 1)
	{
		t = (n / (power(size - i))) % 10;
		*nbr++ = t + 48;
		i++;
	}
	*nbr = 0;
	return (ret);
}
