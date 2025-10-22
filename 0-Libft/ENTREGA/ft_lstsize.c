/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazuaje- <nazuaje-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 19:22:19 by nazuaje-          #+#    #+#             */
/*   Updated: 2025/10/22 21:30:24 by nazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_lstsize(t_list *lst)
{
    t_list  *current;
    int     i;

    i = 0;
    if (!lst)
        return (0);
    *current = lst;
    while (current->next != NULL)
    {
        current = current->next;
        i++;
    }
    return (i);
}