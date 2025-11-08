/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazuaje- <nazuaje-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 19:00:54 by nazuaje-          #+#    #+#             */
/*   Updated: 2025/11/08 09:33:16 by nazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"


int	ft_printf(char const *s, ...)
{
	va_list	arg;
	char	c;
	char	*str;
	int		i;
	float	d;

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
				c = va_arg(arg, int);
				ft_putchar_fd(c,1);
			}
			if (*s == 's')
			{
				str = va_arg(arg, char *);
				ft_putstr_fd(str, 1);
			}
			if (*s == 'p')
			{
				return(0);
			}
			if (*s == 'd')
			{
				d = va_arg(arg, double);
				ft_putnbr_fd(d, 1);
			}
			if (*s == 'i')
			{
				i = va_arg(arg, int);
				ft_putnbr_fd(i, 1);
			}
			if (*s == 'u')
			{
				return(0);
			}
			if (*s == 'x')
			{
				return(0);
			}
			if (*s == 'X')
			{
				return(0);
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