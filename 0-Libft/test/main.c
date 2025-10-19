#include "libft.h"
#include <stdio.h>

static char ft_change_char(unsigned int i, char c)
{
    if (i % 2 == 0)
        return (' ');
    else
        return (c);        
}

void    ft_change_str(unsigned int i, char *str)
{
    (void)i;
    if (!str || !*str)
        return;
    *str = '0';
}

int main(void)
{
    // ft_isalpha y ft_isdigit y ft_isalnum
    printf("ft_isalpha('a'): %d\n", ft_isalpha('a'));
    printf("ft_isalpha('1'): %d\n", ft_isalpha('1'));
    printf("ft_isdigit('5'): %d\n", ft_isdigit('5'));
    printf("ft_isdigit('a'): %d\n", ft_isdigit('a'));
    printf("ft_isalnum('a'): %d\n", ft_isalnum('a'));
    printf("ft_isalnum('7'): %d\n", ft_isalnum('7'));
    printf("ft_isalnum('%%'): %d\n", ft_isalnum('%'));

    // ft_isascii y ft_isprint
    printf("ft_isascii(127): %d\n", ft_isascii(127));
    printf("ft_isascii(128): %d\n", ft_isascii(128));
    printf("ft_isprint(' '): %d\n", ft_isprint(' '));
    printf("ft_isprint('\\n'): %d\n", ft_isprint('\n'));

    // ft_strlen
    char *s_len = "Aqui hay 16 char";
    printf("ft_strlen(\"%s\"): %zu\n", s_len, ft_strlen(s_len));

    // ft_memset y ft_bzero
    char buffer[10];
    ft_memset(buffer, 42, 9);
    buffer[9] = '\0';
    printf("ft_memset (*********): %s\n", buffer);
    ft_bzero(buffer, 9);
    buffer[9] = '\0';
    printf("ft_bzero: %s\n", buffer);

    // ft_memcpy y ft_memmove
    char src[10] = "123456789";
    char dest[10];
    ft_memcpy(dest, src, 10);
    printf("ft_memcpy: %s\n", dest);

    char overlap[20] = "overlaptest12345";
    ft_memmove(overlap + 5, overlap, 0);
    printf("ft_memmove: %s\n", overlap);

    // ft_strlcpy y ft_strlcat
    char str1[20];
    ft_strlcpy(str1, "Hello", sizeof(str1));
    printf("ft_strlcpy: %s\n", str1);
    ft_strlcat(str1, " World", sizeof(str1));
    printf("ft_strlcat: %s\n", str1);

    // ft_toupper y ft_tolower
    printf("ft_toupper('a'): %c\n", ft_toupper('a'));
    printf("ft_tolower('Z'): %c\n", ft_tolower('Z'));

    // ft_strchr y ft_strrchr
    char *s = "Hello World";
    char c = 'o';
    char *pos = ft_strchr(s, c);
    if (pos)
        printf("ft_strchr: %s\n", pos);
    pos = ft_strrchr(s, c);
    if (pos)
        printf("ft_strrchr: %s\n", pos);

    // ft_strncmp
    printf("ft_strncmp(\"abc\", \"abd\", 2): %d\n", ft_strncmp("abc", "abd", 2));
    printf("ft_strncmp(\"abc\", \"abc\", 3): %d\n", ft_strncmp("abc", "abc", 3));

    // ft_memchr
    char *mem_pos = ft_memchr("abcde", 'c', 7);
    printf("ft_memchr (abcde,c,5): %s\n", mem_pos);

    // ft_memcmp
    printf("ft_memcmp(\"abc\", \"abd\", 3): %d\n", ft_memcmp("abc", "abd", 3));
    printf("ft_memcmp(\"abc\", \"abc\", 3): %d\n", ft_memcmp("abc", "abc", 3));

    // ft_strnstr
    char *substr = ft_strnstr("Hello World", "World", 11);
    if (substr)
        printf("ft_strnstr: %s\n", substr);

    // ft_atoi
    printf("ft_atoi(\"  -1234abc\"): %d\n", ft_atoi("  -1234abc"));
    char *ptr_atoi = NULL;
    printf("ft_atoi(\"NULL \"): %d\n", ft_atoi(ptr_atoi));
    printf("ft_atoi(\"-21474836489\"): %d\n", ft_atoi("-21474836489"));


    // ft_calloc
    int *arr = (int *)ft_calloc(5, sizeof(int));
    for (int i = 0; i < 5; i++)
        printf("ft_calloc arr[%d]: %d\n", i, arr[i]);
    free(arr);

    // ft_strdup
    char *dup = ft_strdup("Duplicate me!");
    printf("ft_strdup (Duplicate me!): %s\n", dup);
    free(dup);
    char *dup2 = ft_strdup("");
    printf("ft_strdup (Duplicate me!): %s\n", dup2);
    free(dup2);
    char *dup3 = ft_strdup(NULL);
    printf("ft_strdup (Duplicate me!): %s\n", dup3);
    free(dup3);

    // ft_substr
    char *sub = ft_substr("Hello World", 6, 5);
    printf("ft_substr (Hello World, 6, 5) : %s\n", sub);
    free(sub);

    // ft_strjoin
    char *joined = ft_strjoin("1234","5678");
	printf("ft_strjoin(\"1234\", \"5678\"): %s\n", joined);
	free(joined);

    // ft_strtrim
    char *s_trim = "AB-AB";
    char *set_trim = "";
    char *trim = ft_strtrim(s_trim,set_trim);
	ft_putstr_fd("ft_strtrim ",1);
    ft_putstr_fd(s_trim,1);
    ft_putchar_fd('/',1);
    ft_putstr_fd(set_trim,1);
    ft_putstr_fd(": ",1);
    ft_putendl_fd(trim,1);
	free(trim);

    // ft_split
    char *string = "Hola,Mundo,42";
    char **array = ft_split(string, ',');
    size_t i = 0;
    while (array[i])
    {
        printf("ft_split array[%ld]: %s\n", i, array[i]);        
        free(array[i]);
        i++;
    }
    free(array);
 
    //ft_itoa
    long n_itoa = INT_MIN;//-2147483649;
    char *s_itoa = ft_itoa(n_itoa);
    printf("ft_itoa(%ld): %s\n", n_itoa, s_itoa);
    free(s_itoa);
    int n_itoa2 = -1;
    char *s_itoa2 = ft_itoa(n_itoa2);
    printf("ft_itoa(%d): %s\n", n_itoa2, s_itoa2);
    free(s_itoa2);
    long n_itoa3 = INT_MAX;// 2147483648;
    char *s_itoa3 = ft_itoa(n_itoa3);
    printf("ft_itoa(%ld): %s\n", n_itoa3, s_itoa3);
    free(s_itoa3);



    //ft_strmapi
    char *s_strmapi = "abcdefghijklmn";
    char *r_strmapi = ft_strmapi(s_strmapi, ft_change_char);
    printf("ft_strmapi(%s): %s\n", s_strmapi, r_strmapi);
    free(r_strmapi);

    // ft_striteri
    char s_striteri[5] = "abcd";
    printf("ft_striteri(%s):", s_striteri);
    ft_striteri(s_striteri, ft_change_str);
    printf(" %s\n", s_striteri);

    //ft_putchar_fd & ft_putstr_fd
    char c_fd = 'H';
    ft_putstr_fd("ft_putstr_fd & ft_putchar_fd:",1);
    ft_putchar_fd(c_fd,1);
    ft_putchar_fd('\n',1);

    //ft_putendl_fd
    char *s_fd = "Hola";
    ft_putstr_fd("ft_putendl_fd: ",1);
    ft_putendl_fd(s_fd,1);

    //ft_putnbr_fd
    int n_fd = -1;
    ft_putstr_fd("ft_putnbr_fd: ",1);
    ft_putnbr_fd(n_fd,1);
    ft_putchar_fd('\n',1);

	//valgrind --leak-check=full -s ./main

    return 0;
}
