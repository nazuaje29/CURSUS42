#include <stdio.h>
#include "../ENTREGA/ft_printf.h"

int main(void)
{
    int ret1, ret2;
    char *null_str = NULL;
    int max_int = 2147483647;
    int min_int = -2147483648;
    unsigned int max_uint = 4294967295U;
    void *ptr = (void *)0x7ffee3a0;

    // Test %c
    ret1 = printf("Original %%c: [%c]\n", 'A');
    ret2 = ft_printf("Custom   %%c: [%c]\n", 'A');
    printf("Return values - original: %d, custom: %d\n\n", ret1, ret2);

    // Test %s normal y NULL
    ret1 = printf("Original %%s: [%s]\n", "Hello");
    ret2 = ft_printf("Custom   %%s: [%s]\n", "Hello");
    printf("Return values - original: %d, custom: %d\n\n", ret1, ret2);

    ret1 = printf("Original %%s NULL: [%s]\n", null_str);
    ret2 = ft_printf("Custom   %%s NULL: [%s]\n", null_str);
    printf("Return values - original: %d, custom: %d\n\n", ret1, ret2);

    // Test %p with pointer and NULL
    ret1 = printf("Original %%p: [%p]\n", ptr);
    ret2 = ft_printf("Custom   %%p: [%p]\n", ptr);
    printf("Return values - original: %d, custom: %d\n\n", ret1, ret2);

    ret1 = printf("Original %%p NULL: [%p]\n", NULL);
    ret2 = ft_printf("Custom   %%p NULL: [%p]\n", NULL);
    printf("Return values - original: %d, custom: %d\n\n", ret1, ret2);

    // Test %d and %i with edge values
    ret1 = printf("Original %%d max int: [%d]\n", max_int);
    ret2 = ft_printf("Custom   %%d max int: [%d]\n", max_int);
    printf("Return values - original: %d, custom: %d\n\n", ret1, ret2);

    ret1 = printf("Original %%i min int: [%i]\n", min_int);
    ret2 = ft_printf("Custom   %%i min int: [%i]\n", min_int);
    printf("Return values - original: %d, custom: %d\n\n", ret1, ret2);

    // Test %u with max unsigned int
    ret1 = printf("Original %%u max uint: [%u]\n", max_uint);
    ret2 = ft_printf("Custom   %%u max uint: [%u]\n", max_uint);
    printf("Return values - original: %d, custom: %d\n\n", ret1, ret2);

    // Test %x and %X lower and uppercase hex
    ret1 = printf("Original %%x: [%x]\n", 305441741);
    ret2 = ft_printf("Custom   %%x: [%x]\n", 305441741);
    printf("Return values - original: %d, custom: %d\n\n", ret1, ret2);

    ret1 = printf("Original %%X: [%X]\n", 305441741);
    ret2 = ft_printf("Custom   %%X: [%X]\n", 305441741);
    printf("Return values - original: %d, custom: %d\n\n", ret1, ret2);

    // Test literal %%
    ret1 = printf("Original literal percent: %%\n");
    ret2 = ft_printf("Custom   literal percent: %%\n");
    printf("Return values - original: %d, custom: %d\n\n", ret1, ret2);

    // Test mix of all specifiers
    ret1 = printf("Original mixed: char[%c], str[%s], ptr[%p], dec[%d], uns[%u], hex[%x]\n",
                  'Z', "test", ptr, -42, 12345, 0xBEEF);
    ret2 = ft_printf("Custom   mixed: char[%c], str[%s], ptr[%p], dec[%d], uns[%u], hex[%x]\n",
                    'Z', "test", ptr, -42, 12345, 0xBEEF);
    printf("Return values - original: %d, custom: %d\n\n", ret1, ret2);

    return 0;
}
