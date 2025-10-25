/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazuaje- <nazuaje-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 16:15:25 by nazuaje-          #+#    #+#             */
/*   Updated: 2025/10/25 20:12:37 by nazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_new_content(t_list *lst, t_list *new_lst, void *(*f)(void *),\
	void (*del)(void *))
{
	void	*new_content;

	new_content = f(lst->content);
	if (!new_content)
	{
		ft_lstclear(&new_lst, del);
		return (NULL);
	}
	return (new_content);
}

t_list	*ft_new_node(void *new_content, t_list *new_lst, void (*del)(void *))
{
	t_list	*new_node;

	new_node = ft_lstnew(new_content);
	if (!new_node)
	{
		del(new_content);
		ft_lstclear(&new_lst, del);
		return (NULL);
	}
	return (new_node);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_node;
	void	*new_content;

	if (!lst || !f || !del)
		return (NULL);
	new_lst = NULL;
	while (lst)
	{
		new_content = ft_new_content(lst, new_lst, f, del);
		new_node = ft_new_node(new_content, new_lst, del);
		ft_lstadd_back(&new_lst, new_node);
		lst = lst->next;
	}
	return (new_lst);
}
