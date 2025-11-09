#include <stdio.h>
#include "../ENTREGA/libftprintf.h"

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
	
	ft_printf("Hola%s%cestas, i:%i, d:%d, u:%u, x:%x, X:%X, p:%p", str, c, i, d, u, x, X, p);
	printf("\nHola%s%cestas, i:%i, d:%d, u:%u, x:%x, X:%X, p:%p", str, c, i, d, u, x, X, p);
	return 0;
}