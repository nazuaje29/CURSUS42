#include <stdio.h>
#include "../ENTREGA/ft_printf.h"

int main()
{
	char c = ',';
	char *str = " Como";
	int i = 123456;
	int d = -i;
	unsigned int u = -42;
	int x =  4294967295;
	int X = -31;
	char *p = "hola";
	int result_ft_printf = 0;
	int result_printf = 0;
	
	result_ft_printf = ft_printf("%%Hola%s%cestas, i:%i, d:%d, u:%u, x:%x, X:%X, p:%p", str, c, i, d, u, x, X, p);
	printf("\n"); 
	result_printf = printf("%%Hola%s%cestas, i:%i, d:%d, u:%u, x:%x, X:%X, p:%p", str, c, i, d, u, x, X, p);
	printf("\n"); 

	printf("result_ft_printf: %i\n", result_ft_printf); 
	printf("result_printf: %i\n", result_printf); 

	printf("TEST 36\n"); 

	char *s = NULL;
	result_ft_printf = ft_printf(" NULL %s NULL ", s);
	printf("\n"); 
	result_printf = printf(" NULL %s NULL ", s);
	printf("\n"); 
	printf("result_ft_printf: %i\n", result_ft_printf); 
	printf("result_printf: %i\n", result_printf); 

	printf("TEST 33\n"); 

	int *ptr = 0;
	int *ptr2 = 0;
	result_ft_printf = ft_printf(" %p %p ", ptr, ptr2);
	printf("\n"); 
	result_printf = printf(" %p %p ", ptr, ptr2);
	printf("\n"); 
	printf("result_ft_printf: %i\n", result_ft_printf); 
	printf("result_printf: %i\n", result_printf); 

	return 0;
}