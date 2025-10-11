/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazuaje- <nazuaje-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 16:46:28 by nazuaje-          #+#    #+#             */
/*   Updated: 2025/10/11 16:25:06 by nazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

/*      INCLUDES    */

# include <stdlib.h>
# include <unistd.h>

/*      DEFINES     */

# define TRUE 1
# define FALSE 0
# define BUFFER_SIZE 1024

/*      FUNCTIONS   */

/* Conversions*/
int	ft_atoi(char *str);

/* Char clasification*/
int ft_isalpha(int c);
int ft_isdigit(int c);
int	ft_isalnum(int c);
int	ft_isascii(int c);
int	ft_isprint(int c);




#endif
