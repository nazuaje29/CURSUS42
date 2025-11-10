/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazuaje- <nazuaje-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 07:36:38 by nazuaje-          #+#    #+#             */
/*   Updated: 2025/11/10 09:25:10 by nazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

/* INCLUDES */
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

/* FUNCTIONS */
char	*get_next_line(int fd);
size_t	ft_strlcat(char *dst, const char *src, size_t dsize);

#endif