/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazuaje- <nazuaje-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 07:36:16 by nazuaje-          #+#    #+#             */
/*   Updated: 2025/11/12 19:57:24 by nazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*temp;
	int			bytes;
	size_t		i;
	size_t		j;
	size_t		buffer_len;

	i = 0;
	buffer_len = 0;
	bytes = 0;
	if (fd < 0)
		return (NULL);
	buffer = malloc( BUFFER_SIZE * sizeof(char));
	if (!buffer)
		return (NULL);
	temp = malloc( BUFFER_SIZE * sizeof(char));
	if (!temp)
		return (NULL);
	bytes = read(fd, buffer, BUFFER_SIZE);
	if (bytes == -1)
		return (NULL);
	if (bytes == 0)
		return (NULL);
	while (i < (size_t)bytes)
	{
		if (buffer[i] == '\n')
		{
			return (buffer);
		}
		i++;
	}
	while (bytes > 0)
	{
		buffer_len += bytes;
		bytes = read(fd, temp, BUFFER_SIZE);
		if (bytes == -1)
			return (NULL);
		j = 0;
		while (j < (size_t)bytes)
		{
			if (temp[j] == '\n')
			{
				ft_strlcat(buffer, temp, (buffer_len));
				return (buffer);
			}
			j++;
		}
		ft_strlcat(buffer, temp, (buffer_len));
		free(temp);	
	}
	return (buffer);
}