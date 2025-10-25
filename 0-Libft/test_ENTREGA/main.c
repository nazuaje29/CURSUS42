/* ************************************************************************** */
/*                                                                            */
/*                                 test_lists.c                              */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

/* Funciones auxiliares para test */
void	ft_print_content(void *content)
{
	if (!content)
		printf("(null) ");
	else
		printf("%s ", (char *)content);
}

void	*ft_to_upper(void *content)
{
	if (!content)
		return (NULL);
	char *str = (char *)content;
	char *res = malloc(strlen(str) + 1);
	if (!res)
		return (NULL);
	for (int i = 0; str[i]; i++)
		res[i] = (str[i] >= 'a' && str[i] <= 'z') ? str[i] - 'a' + 'A' : str[i];
	res[strlen(str)] = '\0';
	return (res);
}

void	ft_free_content(void *content)
{
	free(content);
}

/* Imprime la lista mostrando sus contenidos */
void	print_list(t_list *lst)
{
	if (!lst)
	{
		printf("[empty list]\n");
		return;
	}
	while (lst)
	{
		ft_print_content(lst->content);
		lst = lst->next;
	}
	printf("\n");
}

/* Limpia la lista y libera memoria */
void	clear_list(t_list **lst)
{
	ft_lstclear(lst, ft_free_content);
}

int	main(void)
{
	t_list *list = NULL;
	t_list *tmp;
	t_list *mapped;
	int size;

	printf("=== Testing ft_lstnew ===\n");
	tmp = ft_lstnew(strdup("first"));
	if (!tmp)
		printf("Error ft_lstnew: returned NULL\n");
	else
	{
		ft_print_content(tmp->content);
		printf("\n");
	}
	ft_lstclear(&tmp, ft_free_content);

	tmp = ft_lstnew(NULL);
	if (tmp)
	{
		printf("ft_lstnew allows NULL content\n");
		ft_lstdelone(tmp, ft_free_content);
	}
	else
		printf("ft_lstnew rejects NULL content\n");

	printf("\n=== Testing ft_lstadd_front and ft_lstsize ===\n");
	ft_lstadd_front(&list, ft_lstnew(strdup("front1")));
	ft_lstadd_front(&list, ft_lstnew(strdup("front2")));
	print_list(list);
	size = ft_lstsize(list);
	printf("List size: %d (expected 2)\n\n", size);

	printf("=== Testing ft_lstadd_back ===\n");
	ft_lstadd_back(&list, ft_lstnew(strdup("back1")));
	ft_lstadd_back(&list, ft_lstnew(strdup("back2")));
	print_list(list);
	printf("List size now: %d (expected 4)\n\n", ft_lstsize(list));

	printf("=== Testing ft_lstlast ===\n");
	tmp = ft_lstlast(list);
	printf("Last element content: ");
	ft_print_content(tmp->content);
	printf("\n\n");

	printf("=== Testing ft_lstiter ===\n");
	printf("List contents: ");
	ft_lstiter(list, ft_print_content);
	printf("\n\n");

	printf("=== Testing ft_lstmap (to uppercase) ===\n");
	mapped = ft_lstmap(list, ft_to_upper, ft_free_content);
	if (!mapped)
		printf("ft_lstmap failed\n");
	else
	{
		printf("Original: ");
		print_list(list);
		printf("Mapped:   ");
		print_list(mapped);
	}

	printf("\n=== Testing edge cases: NULL input ===\n");
	printf("ft_lstsize(NULL) = %d (expected 0)\n", ft_lstsize(NULL));
	printf("ft_lstlast(NULL) = %p (expected NULL)\n", (void *)ft_lstlast(NULL));
	ft_lstiter(NULL, ft_print_content);
	printf("ft_lstiter on NULL list finished without crash\n");

	tmp = ft_lstmap(NULL, ft_to_upper, ft_free_content);
	printf("ft_lstmap(NULL) = %p (expected NULL)\n", (void *)tmp);

	tmp = ft_lstmap(list, NULL, ft_free_content);
	printf("ft_lstmap(NULL func) = %p (expected NULL)\n", (void *)tmp);

	tmp = ft_lstmap(list, ft_to_upper, NULL);
	printf("ft_lstmap(NULL del) = %p (expected NULL)\n", (void *)tmp);

	printf("\n=== Testing ft_lstdelone ===\n");
	tmp = ft_lstnew(strdup("delete_me"));
	ft_lstdelone(tmp, ft_free_content);
	printf("ft_lstdelone called on single node\n");

	printf("\n=== Testing ft_lstclear ===\n");
	clear_list(&list);
	print_list(list);
	printf("List size after clear: %d (expected 0)\n", ft_lstsize(list));

	if (mapped)
		clear_list(&mapped);

	printf("\n=== All tests completed ===\n");
	return (0);
}
