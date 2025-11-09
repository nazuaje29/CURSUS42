/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazuaje- <nazuaje-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 07:58:54 by nazuaje-          #+#    #+#             */
/*   Updated: 2025/11/09 20:44:08 by nazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr_len(int n)
{
	char	temp;
	int		count;

	count = 0;
	if (n == INT_MIN)
	{
		ft_putstr_fd("-2147483648", 1);
		return (11);
	}
	if (n < 0)
	{
		ft_putchar_fd('-', 1);
		n = -n;
		count += 1;
	}
	if (n > 9)
		count += ft_putnbr_len(n / 10);
	temp = (n % 10) + '0';
	ft_putchar_fd(temp, 1);
	count += 1;
	return (count);
}

int	ft_print_nbr(va_list *arg)
{
	int	nbr;
	int	count;

	nbr = 0;
	nbr = va_arg(*arg, int);
	count = ft_putnbr_len(nbr);
	return (count);
}

static int	ft_putnbr_unsigned_len(unsigned int n)
{
	char	temp;
	int		count;

	count = 0;
	if (n > 9)
		count += ft_putnbr_unsigned_len(n / 10);
	temp = (n % 10) + '0';
	ft_putchar_fd(temp, 1);
	count += 1;
	return (count);
}

int	ft_print_nbr_unsigned(va_list *arg)
{
	unsigned int	nbr;
	int				count;

	nbr = 0;
	nbr = va_arg(*arg, unsigned int);
	count = ft_putnbr_unsigned_len(nbr);
	return (count);
}
