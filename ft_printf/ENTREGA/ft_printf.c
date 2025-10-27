/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazuaje- <nazuaje-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 19:00:54 by nazuaje-          #+#    #+#             */
/*   Updated: 2025/10/27 20:23:55 by nazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"
#include <stdio.h>

int	ft_printf(char const *s, ...)
{
	va_list	arg;

	va_start(arg, s);
	while (*s)
	{
		if (*s != '%' || *(s++) == '%')
			ft_putchar_fd(*s, 1);
		else
		{
			int temp = va_arg(arg, int);
			ft_putnbr_fd(temp ,1);
		}
		s++;		
	}
	va_end(arg);
	return(0);
}

int main()
{
	ft_printf("Hola%Como%estas%", '*', ',', '!');
	printf("\nHola%cComo%cestas%c\n", '*', ',', '!');
	return 0;
}

/*
void va_start(va_list ap, last);
type va_arg(va_list ap, type);
void va_end(va_list ap);
void va_copy(va_list dest, va_list src);
*/