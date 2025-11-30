/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazuaje- <nazuaje-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 07:36:16 by nazuaje-          #+#    #+#             */
/*   Updated: 2025/11/30 11:36:28 by nazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		*residual;
	char			*temp;
	char			buffer[BUFFER_SIZE + 1];
	char			*new_line;
	int				bytes;
	size_t			i;

	i = 0;
	bytes = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (residual == NULL)
    {
        residual = malloc(1);
        residual[0] = '\0';
    }
	while (!ft_strchr(residual,'\n') && bytes != 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(residual);
			residual = NULL;
			return (NULL);
		}
		buffer[bytes] = '\0';
		temp = residual;
		residual = ft_strjoin(residual, buffer);
		free(temp);
		if (!residual)
			return (NULL);
	}
	if (!residual || residual[0] == '\0')
	{
		if (residual)
			free(residual);
		residual = NULL;
		return (NULL);
	}
	while (residual[i] && residual[i] != '\n')
		i++;
	if (residual[i] == '\n')
		i++;
	new_line = ft_substr(residual, 0, i);
	if (!new_line)
		return (NULL);
	temp = residual;
	if (residual[i])
		residual = ft_substr(temp, i, ft_strlen(temp) - i);
	else
		residual = NULL;
	free(temp);
	return(new_line);
}