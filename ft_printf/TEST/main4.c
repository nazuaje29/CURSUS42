#include "../ENTREGA/ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include <float.h>


int main(void)
{
    int ret1, ret2;

    // Mezcla de muchos especificadores con valores extremos
    ret1 = printf("Original multi-edge: %c %s %p %d %i %u %x %X %%\n", 
                  0, "", NULL, INT_MIN, INT_MAX, UINT_MAX, 0, UINT_MAX);
    ret2 = ft_printf("Custom   multi-edge: %c %s %p %d %i %u %x %X %%\n", 
                    0, "", NULL, INT_MIN, INT_MAX, UINT_MAX, 0, UINT_MAX);
    printf("Ret vals - original: %d, custom: %d\n\n", ret1, ret2);

    // Valores muy grandes y negativos para enteros
    ret1 = printf("Original extreme int: %d %i\n", INT_MIN, INT_MAX);
    ret2 = ft_printf("Custom   extreme int: %d %i\n", INT_MIN, INT_MAX);
    printf("Ret vals - original: %d, custom: %d\n\n", ret1, ret2);

    // Punteros nulos y punteros máximos
    void *max_ptr = (void *)ULONG_MAX;
    ret1 = printf("Original pointers: %p %p\n", NULL, max_ptr);
    ret2 = ft_printf("Custom   pointers: %p %p\n", NULL, max_ptr);
    printf("Ret vals - original: %d, custom: %d\n\n", ret1, ret2);

    // Cadena larga casi sin fin
    char very_long_str[1000];
    for (int i = 0; i < 999; i++)
        very_long_str[i] = 'A' + (i % 26);
    very_long_str[999] = '\0';

    ret1 = printf("Original longstr: %s\n", very_long_str);
    ret2 = ft_printf("Custom   longstr: %s\n", very_long_str);
    printf("Ret vals - original: %d, custom: %d\n\n", ret1, ret2);

    // Prueba con ceros y negativos para hex y unsigned
    ret1 = printf("Original hex and unsigned Zero: %x %X %u\n", 0, 0, 0);
    ret2 = ft_printf("Custom   hex and unsigned Zero: %x %X %u\n", 0, 0, 0);
    printf("Ret vals - original: %d, custom: %d\n\n", ret1, ret2);

    ret1 = printf("Original hex and unsigned max: %x %X %u\n", UINT_MAX, UINT_MAX, UINT_MAX);
    ret2 = ft_printf("Custom   hex and unsigned max: %x %X %u\n", UINT_MAX, UINT_MAX, UINT_MAX);
    printf("Ret vals - original: %d, custom: %d\n\n", ret1, ret2);

    // Prueba repetitiva para ver leaks o bloqueos
    for (int i = 0; i < 1000; i++)
        ft_printf("Repeat %d: %s %p %c %x %u %d\n", i, "looptest", &i, (char)(i % 256), i, (unsigned int)i, i);

    return 0;
}
