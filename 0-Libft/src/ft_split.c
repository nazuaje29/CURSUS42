/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazuaje- <nazuaje-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 20:57:20 by nazuaje-          #+#    #+#             */
/*   Updated: 2025/10/15 22:42:20 by nazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

 // 1. Contar cuántas subcadenas se generarán (cuántos separadores hay)
    // 2. Reservar un arreglo de punteros char* para esas subcadenas + 1 para NULL
    // 3. Recorrer la cadena y extraer cada subcadena entre separadores
    // 4. Copiar subcadenas en memoria nueva y asignarlas al arreglo
    // 5. Terminar arreglo con NULL
    // 6. Retornar el arreglo

static	size_t	ft_count_words(char const *s, char c)
{
	size_t	i;
	size_t	words;

	i = 0;
	words = 0;
	if (s[i] == c)
		i++;
	else
		words++;
	while(s[i])
	{
		if (s[i] == c && s[i + 1] != c)
			words++;
		i++;
	}
	return (words);
}

char	**ft_split(char const *s, char c)
{
	size_t	arry_qty;
	
	arry_qty = ft_count_words(s,c);
	
	
}

