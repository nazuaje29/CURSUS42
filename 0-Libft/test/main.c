#include "libft.h"
#include <stdio.h>

static	size_t	ft_count_words(char const *s, char c)
{
	size_t	i;
	size_t	words;

	i = 0;
	words = 0;/*
	if (s[i] == c)
		i++;
	else
		words++;*/
	while(s[i])
	{
		while(s[i])
        if (s[i] == c)
			words++;
		i++;
	}
	return (words);
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
    printf("ft_strlen(\"-TEST-AB\"): %zu\n", ft_strlen("-TEST-AB"));

    // ft_memset y ft_bzero
    char buffer[10];
    ft_memset(buffer, 'x', 9);
    buffer[9] = '\0';
    printf("ft_memset: %s\n", buffer);
    ft_bzero(buffer, 9);
    buffer[9] = '\0';
    printf("ft_bzero: %s\n", buffer);

    // ft_memcpy y ft_memmove
    char src[10] = "123456789";
    char dest[10];
    ft_memcpy(dest, src, 10);
    printf("ft_memcpy: %s\n", dest);

    char overlap[20] = "overlaptest12345";
    ft_memmove(overlap + 5, overlap, 10);
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
    char *pos = ft_strchr("Hello World", 'o');
    if (pos)
        printf("ft_strchr: %s\n", pos);
    pos = ft_strrchr("Hello World", 'o');
    if (pos)
        printf("ft_strrchr: %s\n", pos);

    // ft_strncmp
    printf("ft_strncmp(\"abc\", \"abd\", 2): %d\n", ft_strncmp("abc", "abd", 2));
    printf("ft_strncmp(\"abc\", \"abc\", 3): %d\n", ft_strncmp("abc", "abc", 3));

    // ft_memchr
    char *mem_pos = ft_memchr("abcde", 'c', 5);
    if (mem_pos)
        printf("ft_memchr: %c\n", *mem_pos);

    // ft_memcmp
    printf("ft_memcmp(\"abc\", \"abd\", 3): %d\n", ft_memcmp("abc", "abd", 3));
    printf("ft_memcmp(\"abc\", \"abc\", 3): %d\n", ft_memcmp("abc", "abc", 3));

    // ft_strnstr
    char *substr = ft_strnstr("Hello World", "World", 11);
    if (substr)
        printf("ft_strnstr: %s\n", substr);

    // ft_atoi
    printf("ft_atoi(\"  -1234abc\"): %d\n", ft_atoi("  -1234abc"));

    // ft_calloc
    int *arr = (int *)ft_calloc(5, sizeof(int));
    for (int i = 0; i < 5; i++)
        printf("ft_calloc arr[%d]: %d\n", i, arr[i]);
    free(arr);

    // ft_strdup
    char *dup = ft_strdup("Duplicate me!");
    printf("ft_strdup (Duplicate me!): %s\n", dup);
    free(dup);

    // ft_substr
    char *sub = ft_substr("Hello World", 6, 5);
    printf("ft_substr (Hello World, 6, 5) %s\n", sub);
    free(sub);

    // ft_strjoin
    char *joined = ft_strjoin("1234","5678");
	printf("ft_strjoin(\"1234\", \"5678\"): %s\n", joined);
	free(joined);

    // ft_strtrim
    char *trim = ft_strtrim("AB-TEST-AB","AB");
	printf("ft_strtrim(\"AB-TEST-AB\", \"AB\"): %s\n", trim);
	free(trim);

	//valgrind --leak-check=full -s ./main

    // ft_count_words
    size_t words = ft_count_words(",hola,mundo,42", ',');
    printf("ft_count_words: %ld\n", words);

    return 0;
}
