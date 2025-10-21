/* ************************************************************************** */
/*																		    */
/*														:::      ::::::::   */
/*   ft_split.c										 :+:      :+:    :+:   */
/*												    +:+ +:+		 +:+     */
/*   By: nazuaje- <nazuaje-@student.42madrid.com    +#+  +:+       +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/10/15 20:57:20 by nazuaje-		  #+#    #+#		     */
/*   Updated: 2025/10/18 07:39:43 by nazuaje-		 ###   ########.fr       */
/*																		    */
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
		ft_free_array(array, i);
	return (len);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	array_qty;
	char	**array;

	i = 0;
	if (!s)
		return (NULL);
	array_qty = ft_count_words(s, c);
	array = malloc((array_qty + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	while (i < array_qty)
	{
		if (*s != c)
		{
			s = s + ft_new_array(array, s, c, i);
			i++;
		}
		else
			s++;
	}
	array[i] = NULL;
	return (array);
}
