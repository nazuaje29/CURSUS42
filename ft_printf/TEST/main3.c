#include <stdio.h>
#include <limits.h>
#include "../ENTREGA/ft_printf.h"

int main(void)
{
    int ret1, ret2;

    char *empty = "";
    char *long_str = "Este es un string muy largo para probar si el ft_printf soporta bien strings extensos.";

    void *max_ptr = (void *)ULONG_MAX;
    void *null_ptr = NULL;

    unsigned int max_uint = UINT_MAX;
    int min_int = INT_MIN;
    int max_int = INT_MAX;

	char *null_str = NULL;
    // Edge cases with empty string and NULL
    ret1 = printf("Original empty string: [%s]\n", empty);
    ret2 = ft_printf("Custom   empty string: [%s]\n", empty);
    printf("Ret vals - original: %d, custom: %d\n\n", ret1, ret2);

    ret1 = printf("Original NULL string: [%s]\n", null_str);
    ret2 = ft_printf("Custom   NULL string: [%s]\n", null_str);
    printf("Ret vals - original: %d, custom: %d\n\n", ret1, ret2);

    // Pointer test: NULL and max pointer value
    ret1 = printf("Original NULL pointer: [%p]\n", null_ptr);
    ret2 = ft_printf("Custom   NULL pointer: [%p]\n", null_ptr);
    printf("Ret vals - original: %d, custom: %d\n\n", ret1, ret2);

    ret1 = printf("Original max pointer: [%p]\n", max_ptr);
    ret2 = ft_printf("Custom   max pointer: [%p]\n", max_ptr);
    printf("Ret vals - original: %d, custom: %d\n\n", ret1, ret2);

    // Integer edge cases: min and max int
    ret1 = printf("Original INT_MIN: [%d]\n", min_int);
    ret2 = ft_printf("Custom   INT_MIN: [%d]\n", min_int);
    printf("Ret vals - original: %d, custom: %d\n\n", ret1, ret2);

    ret1 = printf("Original INT_MAX: [%d]\n", max_int);
    ret2 = ft_printf("Custom   INT_MAX: [%d]\n", max_int);
    printf("Ret vals - original: %d, custom: %d\n\n", ret1, ret2);

    // Unsigned int max value and zero
    ret1 = printf("Original UINT_MAX: [%u]\n", max_uint);
    ret2 = ft_printf("Custom   UINT_MAX: [%u]\n", max_uint);
    printf("Ret vals - original: %d, custom: %d\n\n", ret1, ret2);

    ret1 = printf("Original zero unsigned: [%u]\n", 0);
    ret2 = ft_printf("Custom   zero unsigned: [%u]\n", 0);
    printf("Ret vals - original: %d, custom: %d\n\n", ret1, ret2);

    // Hex tests with 0, max, and arbitrary values
    ret1 = printf("Original zero hex: [%x]\n", 0);
    ret2 = ft_printf("Custom   zero hex: [%x]\n", 0);
    printf("Ret vals - original: %d, custom: %d\n\n", ret1, ret2);

    ret1 = printf("Original max uint hex: [%x]\n", max_uint);
    ret2 = ft_printf("Custom   max uint hex: [%x]\n", max_uint);
    printf("Ret vals - original: %d, custom: %d\n\n", ret1, ret2);

    ret1 = printf("Original mixed hex: [%x] [%X]\n", 305441741, 305441741);
    ret2 = ft_printf("Custom   mixed hex: [%x] [%X]\n", 305441741, 305441741);
    printf("Ret vals - original: %d, custom: %d\n\n", ret1, ret2);

    // Single char boundary cases and %%
    ret1 = printf("Original char edge: [%c]\n", 0);
    ret2 = ft_printf("Custom   char edge: [%c]\n", 0);
    printf("Ret vals - original: %d, custom: %d\n\n", ret1, ret2);

    ret1 = printf("Original percent: %%\n");
    ret2 = ft_printf("Custom   percent: %%\n");
    printf("Ret vals - original: %d, custom: %d\n\n", ret1, ret2);

    // Long string print
    ret1 = printf("Original long str: [%s]\n", long_str);
    ret2 = ft_printf("Custom   long str: [%s]\n", long_str);
    printf("Ret vals - original: %d, custom: %d\n\n", ret1, ret2);

    return 0;
}
