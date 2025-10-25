/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazuaje- <nazuaje-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 16:15:25 by nazuaje-          #+#    #+#             */
/*   Updated: 2025/10/25 17:18:14 by nazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list  *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    t_list  *new_lst;

    if (!lst || !f || !del)
        return (NULL);
    while (lst)
    {
        new_lst = ft_lstnew(lst->content);
            if (!new_lst)
                return (NULL);
        f(new_lst);
        lst = lst->next;
    }
    return (new_lst);
}