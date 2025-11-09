/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned_fd.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazuaje- <nazuaje-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 08:28:54 by nazuaje-          #+#    #+#             */
/*   Updated: 2025/11/09 08:51:42 by nazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putnbr_unsigned_fd(unsigned int n, int fd)
{
	char	temp;

	if (n > 9)
		ft_putnbr_unsigned_fd(n / 10, fd);
	temp = (n % 10) + '0';
	ft_putchar_fd(temp, 1);
}
