/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazuaje- <nazuaje-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 19:00:54 by nazuaje-          #+#    #+#             */
/*   Updated: 2025/11/09 09:14:58 by nazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(char const *s, ...)
{
	va_list			arg;
	t_val_type		val;

	va_start(arg, s);
	while (*s)
	{
		if (*s != '%')
			ft_putchar_fd(*s, 1);
		else
		{
			s++;
			if (*s == '%')
				ft_putchar_fd(*s,1);
			if (*s == 'c')
			{
				val.c = va_arg(arg, int);
				ft_putchar_fd(val.c,1);
			}
			if (*s == 's')
			{
				val.s = va_arg(arg, char *);
				ft_putstr_fd(val.s, 1);
			}
			if (*s == 'p')
			{
				val.ul = (unsigned long)(void *)va_arg(arg, void *);
				ft_putstr_fd("0x", 1);
				ft_putnbr_base_unsigned(val.ul, "0123456789abcdef");
			}
			if (*s == 'i' || *s == 'd')
			{
				val.i = va_arg(arg, int);
				ft_putnbr_fd(val.i, 1);
			}
			if (*s == 'u')
			{
				val.ui = va_arg(arg, unsigned int);
				ft_putnbr_unsigned_fd(val.ui, 1);
			}
			if (*s == 'x')
			{
				val.ui = va_arg(arg, unsigned int);
				ft_putnbr_base_unsigned(val.ui, "0123456789abcdef");
			}
			if (*s == 'X')
			{
				val.ui = va_arg(arg, unsigned int);
				ft_putnbr_base_unsigned(val.ui, "0123456789ABCDEF");
			}	
		}
		s++;		
	}
	va_end(arg);
	return(0);
}

/*
void va_start(va_list ap, last);
type va_arg(va_list ap, type);
void va_end(va_list ap);
void va_copy(va_list dest, va_list src);
*/