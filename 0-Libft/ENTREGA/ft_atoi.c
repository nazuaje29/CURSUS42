/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazuaje- <nazuaje-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 15:30:10 by nazuaje-          #+#    #+#             */
/*   Updated: 2025/10/21 22:40:29 by nazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static int	ft_get_number(const char *str, int sign)
{
	long	result;
	char	*s;

	result = 0;
	s = (char *)str;
	while (*s >= '0' && *s <= '9')
	{
		if (sign == 1)
		{
			if (result >= INT_MAX / 10)
				return (INT_MAX);
		}
		else
		{
			if (result <= INT_MIN / 10)
				return (INT_MIN);
		}
		result = (result * 10) + *s - '0';
		s++;
	}
	return ((int)result * sign);
}

int	ft_atoi(const char *str)
{
	int		sign;
	char	*s;

	sign = 1;
	s = (char *)str;
	if (!s)
		return (0);
	while ((*s >= 9 && *s <= 13) || *s == 32)
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -sign;
		s++;
	}
	return (ft_get_number(s, sign));
}
