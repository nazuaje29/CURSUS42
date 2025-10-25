#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

void ft_freecontent(void *content)
{
    if (content)   
        free(content);    
}

int main(void)
{
    t_list  *lst = NULL;
    t_list  *node1;
    t_list  *node2;
    t_list  *node3;
    t_list  *last;
    int     size;
    int     *n1 = malloc(sizeof(int));
    int     *n2 = malloc(sizeof(int));
    int     *n3 = malloc(sizeof(int));
    t_list *tmp;

    *n1 = 10;
    *n2 = 20;
    *n3 = 30;
    printf("Lista inicial: ");
    tmp = lst;
    while (tmp)
    {
        printf("%i\n", *(int *)tmp->content);
        tmp = tmp->next;
    }
    printf("\n");
    node1 = ft_lstnew(n1);
    node2 = ft_lstnew(n2);
    node3 = ft_lstnew(n3);
    ft_lstadd_front(&lst, node1);
    ft_lstadd_front(&lst, node3);
    printf("Lista con node 1 y 3 al inicio: ");
    tmp = lst;
    while (tmp)
    {
        printf("%i ", *(int *)tmp->content);
        tmp = tmp->next;
    }
    printf("\nLista con node 2 al final: ");
    ft_lstadd_back(&lst, node2);
    tmp = lst;
    while (tmp)
    {
        printf("%i ", *(int *)tmp->content);
        tmp = tmp->next;
    }
    printf("\n");
    size = ft_lstsize(lst);
    last = ft_lstlast(lst);
    printf("Tamaño de la lista: %i\n", size);
    printf("Contenido ultimo nodo de la lista: %i\n", *(int *)last->content);

  

    return (0);
}

	//valgrind --leak-check=full -s ./main


