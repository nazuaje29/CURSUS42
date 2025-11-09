/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazuaje- <nazuaje-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 18:53:30 by nazuaje-          #+#    #+#             */
/*   Updated: 2025/11/09 20:44:03 by nazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/* INCLUDES */
# include <stdarg.h>
# include <limits.h>
# include "libft/libft.h"

/* FUNCTIONS */
int	ft_printf(char const *s, ...);
int	ft_print_nbr_unsigned(va_list *arg);
int	ft_print_nbr(va_list *arg);
int	ft_print_ptr(va_list *arg);
int	ft_print_hexa(va_list *arg, char const *s);

#endif