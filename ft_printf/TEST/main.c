#include <stdio.h>
#include "../ENTREGA/libftprintf.h"

int main()
{
	char c = ',';
	char *str = " Como";
	int i = 123456;
	float d = 3.141516;
	
	ft_printf("Hola%s%cestas %i, %d:", str, c, i, d);
	printf("\nHola%s%cestas %i, %d:", str, c, i, d);
	return 0;
}