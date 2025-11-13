/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazuaje- <nazuaje-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 07:36:16 by nazuaje-          #+#    #+#             */
/*   Updated: 2025/11/13 20:21:20 by nazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*residual;
	char		*content;
	char		*buffer;
	char		*new_line;
	int			bytes;
	size_t		i;

	i = 0;
	bytes = 1;
	content = "";
	if (fd < 0)
		return (NULL);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while (ft_strchr(residual,'\n') != NULL && bytes != 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes] = '\0';
		content = ft_strjoin(content, buffer);
		if (!content)
		{
			free(buffer);
			return (NULL);
		}	
	}
	while (content[i] && content[i] != '\n')
		i++;
	new_line = ft_substr(content, 0, i);
	if (!new_line)
		return (NULL);
	residual = ft_substr(content, i, ft_strlen(content) - i);
	if (!residual)
	{	
		return (NULL);
	}
	return(new_line);
}