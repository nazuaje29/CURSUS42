/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazuaje- <nazuaje-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 09:35:04 by nazuaje-          #+#    #+#             */
/*   Updated: 2025/10/26 18:49:56 by nazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static void	ft_fill_string(char *s, int is_neg, size_t len_nbr, unsigned int n)
{
	size_t	i;

	i = len_nbr - 1;
	if (is_neg == 1)
		s[0] = '-';
	while (n > 0)
	{
		s[i] = n % 10 + '0';
		n = n / 10;
		i--;
	}
	s[len_nbr] = '\0';
}

static char	*ft_check_input(int n)
{
	char	*s;

	if (n == INT_MIN)
	{
		s = malloc((12) * sizeof(char));
		if (!s)
			return (NULL);
		ft_strlcpy(s, "-2147483648", 12);
		return (s);
	}
	if (n == 0)
	{
		s = malloc(2 * sizeof(char));
		if (!s)
			return (NULL);
		ft_strlcpy(s, "0", 2);
		return (s);
	}
	return (NULL);
}

size_t	ft_len_nbr(unsigned int n)
{
	size_t	len_nbr;

	len_nbr = 0;
	while (n > 0)
	{
		n = n / 10;
		len_nbr++;
	}
	return (len_nbr);
}

static void	ft_check_negative(int *is_neg, size_t *len_nbr, int n, unsigned \
	int *nbr)
{
	if (n < 0)
	{
		*is_neg = 1;
		*len_nbr = *len_nbr + 1;
		*nbr = (unsigned int)(-n);
	}
}

char	*ft_itoa(int n)
{
	char			*s;
	char			*special_case;
	size_t			len_nbr;
	int				is_neg;
	unsigned int	nbr;

	len_nbr = 0;
	is_neg = 0;
	nbr = (unsigned int)(n);
	if (n == 0 || n == INT_MIN)
	{
		special_case = ft_check_input(n);
		if (!special_case)
			return (NULL);
		return (special_case);
	}
	ft_check_negative(&is_neg, &len_nbr, n, &nbr);
	len_nbr = len_nbr + ft_len_nbr(nbr);
	s = malloc((len_nbr + 1) * sizeof(char));
	if (!s)
		return (NULL);
	ft_fill_string(s, is_neg, len_nbr, nbr);
	return (s);
}
