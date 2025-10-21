/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazuaje- <nazuaje-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 15:30:10 by nazuaje-          #+#    #+#             */
/*   Updated: 2025/10/21 17:25:32 by nazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_number(const char *str, int sign)
{
	int		result;
	char	*s;

	result = 0;
	s = (char *)str;
	while (*str >= '0' && *str <= '9')
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
		result = (result * 10) + *str - '0';
		str++;
	}
	return (result);
}

int	ft_atoi(const char *str)
{
	int		result;
	int		sign;
	char	*s;

	result = 0;
	sign = 1;
	s = (char *)str;
	if (!str)
		return (0);
	while ((*s >= 9 && *s <= 13) || *s == 32)
		s++;
	if (*s == '-')
	{
		sign = -sign;
		s++;
	}
	else if (*s == '+')
		s++;
	result = ft_get_number(s, sign);
	return (result * sign);
}
