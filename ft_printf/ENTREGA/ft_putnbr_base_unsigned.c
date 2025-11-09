/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_unsigned.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazuaje- <nazuaje-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 07:58:54 by nazuaje-          #+#    #+#             */
/*   Updated: 2025/11/09 09:12:46 by nazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (base[i])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[j] == base[i])
				return (0);
			j++;
		}
		if (base[i] == '-' || base[i] == '+')
			return (0);
		i++;
	}
	if (i <= 1)
		return (0);
	return (i);
}

void	ft_putnbr_base_unsigned(unsigned long nbr, char *base)
{
	size_t	base_len;
	long	temp;

	base_len = ft_check_base(base);
	if (base_len == 0)
		return ;
	if (nbr > base_len - 1)
		ft_putnbr_base_unsigned(nbr / base_len, base);
	temp = (nbr % base_len);
	temp = base[temp];
	write(1, &temp, 1);
}
