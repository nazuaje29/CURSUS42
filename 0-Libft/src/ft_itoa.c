/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazuaje- <nazuaje-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 09:35:04 by nazuaje-          #+#    #+#             */
/*   Updated: 2025/10/18 10:30:35 by nazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	ft_fill_string(char *s, int is_neg, size_t len_nbr, int n)
{
	size_t	i;

	i = 0;
	if (is_neg == 1)
	{
		s[0] = '-';
	}
	i = len_nbr - 1;
	while (n > 0)
	{
		s[i] = n % 10 + '0';
		n = n / 10;
		i--;
	}
	s[len_nbr] = '\0';
}

char	*ft_itoa(int n)
{
	char	*s;
	size_t	len_nbr;
	int		is_neg;
	int		nbr;

	len_nbr = 0;
	is_neg = 0;
	nbr = n;
	if (n < 0)
	{
		n = -n;
		nbr = -nbr;
		len_nbr++;
		is_neg = 1;
	}
	while (nbr > 0)
	{
		nbr = nbr / 10;
		len_nbr++;
	}
	s = malloc((len_nbr + 1) * sizeof(char));
	if (!s)
		return (NULL);
	ft_fill_string(s, is_neg, len_nbr, n);
	return (s);
}
