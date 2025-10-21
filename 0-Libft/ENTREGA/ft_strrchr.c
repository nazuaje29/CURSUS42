/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazuaje- <nazuaje-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 12:50:36 by nazuaje-          #+#    #+#             */
/*   Updated: 2025/10/21 23:13:20 by nazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last;
	char	*str;

	last = NULL;
	str = (char *)s;
	while (*str)
	{
		if (*str == (char)c)
			last = (char *)str;
		str++;
	}
	if (c == '\0')
		return ((char *)str);
	return ((char *)last);
}
