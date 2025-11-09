/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazuaje- <nazuaje-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 18:53:30 by nazuaje-          #+#    #+#             */
/*   Updated: 2025/11/09 09:14:15 by nazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

/* INCLUDES */
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include "libft/libft.h"

/* DEFINES */

/* STRUCTURES */
typedef union variable_type
{
	int				i;
	unsigned int	ui;
	unsigned long	ul;
	char			c;
	char			*s;
}					t_val_type;

/* FUNCTIONS */
int		ft_printf(char const *, ...);
void	ft_putnbr_base_unsigned(unsigned long nbr, char *base);
void	ft_putnbr_unsigned_fd(unsigned int n, int fd);

/* Conversions*/

/* Char Management */

/* String Management */

/* Memory Management */

/* File Descriptor Management */

/* List Management */

#endif