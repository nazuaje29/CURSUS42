/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazuaje- <nazuaje-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 08:28:54 by nazuaje-          #+#    #+#             */
/*   Updated: 2025/11/12 17:27:09 by nazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr_base_unsigned(unsigned long nbr, char *base)
{
	size_t	base_len;
	long	temp;
	int		count;

	count = 0;
	base_len = 16;
	if (nbr > base_len - 1)
		count += ft_putnbr_base_unsigned(nbr / base_len, base);
	temp = (nbr % base_len);
	temp = base[temp];
	write(1, &temp, 1);
	count += 1;
	return (count);
}

int	ft_print_ptr(va_list *arg)
{
	unsigned long	ptr;
	int				count;

	ptr = 0;
	ptr = (unsigned long)(void *)va_arg(*arg, void *);
	if (!ptr)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	ft_putstr_fd("0x", 1);
	count = 2 + ft_putnbr_base_unsigned(ptr, "0123456789abcdef");
	return (count);
}

int	ft_print_hexa(va_list *arg, char const *s)
{
	unsigned int	nbr;
	int				count;
	char			*base;

	count = 0;
	if (*s == 'x')
		base = "0123456789abcdef";
	if (*s == 'X')
		base = "0123456789ABCDEF";
	nbr = va_arg(*arg, unsigned int);
	count += ft_putnbr_base_unsigned(nbr, base);
	return (count);
}
