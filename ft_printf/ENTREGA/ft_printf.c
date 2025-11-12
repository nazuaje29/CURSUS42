/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazuaje- <nazuaje-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 19:00:54 by nazuaje-          #+#    #+#             */
/*   Updated: 2025/11/12 17:26:44 by nazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_original(char const *s)
{
	ft_putchar_fd(*s, 1);
	return (1);
}

static int	ft_print_char(va_list *arg)
{
	char	c;

	c = va_arg(*arg, int);
	ft_putchar_fd(c, 1);
	return (1);
}

static int	ft_print_str(va_list *arg)
{
	char	*str;

	str = va_arg(*arg, char *);
	if (!str)
		str = "(null)";
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

static int	ft_printer(char const *s, va_list *arg)
{
	int	count;

	count = 0;
	if (*s == 'c')
		count += ft_print_char(arg);
	else if (*s == 's')
		count += ft_print_str(arg);
	else if (*s == 'p')
		count += ft_print_ptr(arg);
	else if (*s == 'i' || *s == 'd')
		count += ft_print_nbr(arg);
	else if (*s == 'u')
		count += ft_print_nbr_unsigned(arg);
	else if (*s == 'x' || *s == 'X')
		count += ft_print_hexa(arg, s);
	return (count);
}

int	ft_printf(char const *s, ...)
{
	va_list		arg;
	int			count;

	count = 0;
	va_start(arg, s);
	while (*s)
	{
		if (*s != '%')
			count += ft_print_original(s);
		else
		{
			s++;
			if (*s == '%')
				count += ft_print_original(s);
			else
				count += ft_printer(s, &arg);
		}
		s++;
	}
	va_end(arg);
	return (count);
}
