/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazuaje- <nazuaje-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 21:03:23 by nazuaje-          #+#    #+#             */
/*   Updated: 2025/10/14 21:11:48 by nazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed_str;
	size_t	end;

	while (ft_strchr(set, s1[0]))
		s1++;
	end = ft_strlen(s1);
	while (ft_strchr(set, s1[end - 1]))
		end--;
	trimmed_str = ft_calloc((end + 1), sizeof(char));
	if (!trimmed_str)
		return (NULL);
	ft_strlcat(trimmed_str, s1, (end + 1));
	return (trimmed_str);
}
