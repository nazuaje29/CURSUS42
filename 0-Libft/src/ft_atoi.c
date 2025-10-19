/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazuaje- <nazuaje-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 15:30:10 by nazuaje-          #+#    #+#             */
/*   Updated: 2025/10/19 16:44:48 by nazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(char *str)
{
	int		result;
	int		sign;

	result = 0;
	sign = 1;
	if (!str)
		return (0);
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-')
		sign = -sign;
	str++;
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
	return (result * sign);
}
