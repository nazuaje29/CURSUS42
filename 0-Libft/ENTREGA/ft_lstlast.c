/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazuaje- <nazuaje-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 20:59:23 by nazuaje-          #+#    #+#             */
/*   Updated: 2025/10/22 21:03:29 by nazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list  *ft_lstlast(t_list *lst)
{
    t_list  *current;
    t_list  *last;
    
    if (!lst)
        return (NULL);
    *current = *lst;
    while (current->next != NULL)
    {
        *last = *current;
        current = current->next;
    }
    return (last);
}