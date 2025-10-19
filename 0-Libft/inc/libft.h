/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazuaje- <nazuaje-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 16:46:28 by nazuaje-          #+#    #+#             */
/*   Updated: 2025/10/19 09:24:13 by nazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

/*      INCLUDES    */

# include <stdlib.h>
# include <unistd.h>

/*      DEFINES     */

# define TRUE 1
# define FALSE 0
# define BUFFER_SIZE 1024

/*      FUNCTIONS   */

/* Conversions*/
int	ft_atoi(char *str);
char	*ft_itoa(int n);

/* Char Management*/
int ft_isalpha(int c);
int ft_isdigit(int c);
int	ft_isalnum(int c);
int	ft_isascii(int c);
int	ft_isprint(int c);
int ft_toupper(int c);
int	ft_tolower(int c);

/* String Management*/
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t dsize); /* dst debe ser del tamaño dsize*/
size_t	ft_strlcat(char *dst, const char *src, size_t dsize); /* dsize debe ser mayor a dst*/
char 	*ft_strchr(const char *s, int c); /* Devuelve un puntero a la primera ocurrencia del caracter c en la string s o NULL si no se encuentra. Si c es '\0', devuelve un puntero al final de la string s.*/
char 	*ft_strrchr(const char *s, int c); /* Devuelve un puntero a la última ocurrencia del caracter c en la string s o NULL si no se encuentra. Si c es '\0', devuelve un puntero al final de la string s.*/
int		ft_strncmp(const char *s1, const char *s2, size_t n); /* Compara las dos strings s1 y s2 hasta n caracteres. Devuelve un valor negativo, cero o positivo si s1 es menor, igual o mayor que s2 respectivamente.*/
char	*ft_strnstr(const char *big, const char *little, size_t len); /* Busca la primera ocurrencia de la string little en la string big, pero solo en los primeros len caracteres de big. Devuelve un puntero a la posición encontrada o NULL si no se encuentra. Si little es una string vacía, devuelve big.*/
char	*ft_substr(char const *s, unsigned int start, size_t len); /* Devuelve una nueva string que es una subcadena de s, comenzando en el índice start y con una longitud máxima de len. Si start está fuera de los límites de s, devuelve una string vacía. Si len es mayor que la longitud restante de s desde start, ajusta len para que no exceda la longitud de s.*/
char	*ft_strdup(const char *s); /* Devuelve un puntero a una nueva string que es una copia de la string s. La memoria para la nueva string se reserva con malloc y debe ser liberada con free cuando ya no se necesite. Si no se puede reservar memoria, devuelve NULL.*/
char	*ft_strjoin(char const *s1, char const *s2); /* Devuelve una nueva string que es la concatenación de las strings s1 y s2. La memoria para la nueva string se reserva con malloc y debe ser liberada con free cuando ya no se necesite. Si no se puede reservar memoria, devuelve NULL. Si s1 o s2 son NULL, se tratan como strings vacías. */
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));


/* Memory Management*/
void	*ft_memset(void *s, int c, size_t n); /* s debe ser del tamaño n*/
void	ft_bzero(void *s, size_t n); /* s debe ser del tamaño n*/
void	*ft_memcpy(void *dest, const void *src, size_t n); /* dest y src deben ser del tamaño n, src y dst no pueden solaparse*/
void	*ft_memmove(void *dest, const void *src, size_t n); /* dest y src deben ser del tamaño n, si pueden solaparse*/
void	*ft_memchr(const void *s, int c, size_t n); /* Busca la primera ocurrencia del caracter c (convertido a unsigned char) en los primeros n bytes de la zona de memoria apuntada por s. Devuelve un puntero a la posición encontrada o NULL si no se encuentra.*/
int		ft_memcmp(const void *s1, const void *s2, size_t n); /* Compara los primeros n bytes de las zonas de memoria s1 y s2. Devuelve un valor negativo, cero o positivo si s1 es menor, igual o mayor que s2 respectivamente.*/
void	*ft_calloc(size_t nmemb, size_t size); /* Reserva memoria para un array de nmemb elementos de size bytes cada uno e inicializa toda la memoria a cero. Devuelve un puntero a la memoria reservada o NULL si no se puede reservar la memoria. Si nmemb o size es 0, devuelve un puntero a una zona de memoria válida que no debe ser utilizada.*/

/* File Descriptor Management*/
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);


#endif
