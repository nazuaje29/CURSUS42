/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazuaje- <nazuaje-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 20:51:42 by nazuaje-          #+#    #+#             */
/*   Updated: 2025/10/14 19:59:41 by nazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*joined_str;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	joined_str = ft_calloc((s1_len + s2_len + 1), sizeof(char));
	if (!joined_str)
		return (NULL);
	ft_strlcat(joined_str, s1, s1_len + 1);
	ft_strlcat(joined_str + s1_len, s2, s1_len + s2_len + 1);
	return (joined_str);
}
