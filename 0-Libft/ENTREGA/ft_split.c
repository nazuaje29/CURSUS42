/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazuaje- <nazuaje-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 18:23:10 by nazuaje-          #+#    #+#             */
/*   Updated: 2025/10/26 18:23:51 by nazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_count_words(char const *s, char c)
{
	size_t	i;
	size_t	words;
	size_t	flag;

	i = 0;
	words = 0;
	flag = 1;
	while (s[i])
	{
		if (s[i] == c)
			flag = 1;
		if (s[i] != c && flag == 1)
		{
			words++;
			flag = 0;
		}
		i++;
	}
	return (words);
}

static char	*ft_free_array(char **array, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (NULL);
}

static size_t	ft_new_array(char **array, char const *s, char c, size_t i)
{
	char	*temp;
	size_t	len;

	temp = ft_strchr(s, c);
	if (temp == NULL)
		len = ft_strlen(s);
	else
		len = temp - s;
	array[i] = ft_substr(s, 0, len);
	if (!array[i])
	{
		ft_free_array(array, i);
		return (0);
	}
	return (len);
}

static char	**ft_array_create(char **array, const char *s, char c, size_t a_qty)
{
	size_t	i;
	size_t	new_array_len;

	i = 0;
	while (i < a_qty)
	{
		if (*s != c)
		{
			new_array_len = ft_new_array(array, s, c, i);
			if (!new_array_len)
				return (NULL);
			s = s + new_array_len;
			i++;
		}
		else
			s++;
	}
	array[i] = NULL;
	return (array);
}

char	**ft_split(char const *s, char c)
{
	size_t	array_qty;
	char	**array;

	if (!s)
		return (NULL);
	array_qty = ft_count_words(s, c);
	array = malloc((array_qty + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	array = ft_array_create(array, s, c, array_qty);
	if (!array)
		return (NULL);
	return (array);
}
