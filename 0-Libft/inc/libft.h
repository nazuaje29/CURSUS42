/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazuaje- <nazuaje-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 16:46:28 by nazuaje-          #+#    #+#             */
/*   Updated: 2025/10/12 14:57:34 by nazuaje-         ###   ########.fr       */
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





/* Memory Management*/
void	*ft_memset(void *s, int c, size_t n); /* s debe ser del tamaño n*/
void	ft_bzero(void *s, size_t n); 
void	*ft_memcpy(void *dest, const void *src, size_t n); /* dest y src deben ser del tamaño n, src y dst no pueden solaparse*/
void	*ft_memmove(void *dest, const void *src, size_t n); /* dest y src deben ser del tamaño n, si pueden solaparse*/
void	*ft_memchr(const void *s, int c, size_t n); /* Busca la primera ocurrencia del caracter c (convertido a unsigned char) en los primeros n bytes de la zona de memoria apuntada por s. Devuelve un puntero a la posición encontrada o NULL si no se encuentra.*/
int		ft_memcmp(const void *s1, const void *s2, size_t n); /* Compara los primeros n bytes de las zonas de memoria s1 y s2. Devuelve un valor negativo, cero o positivo si s1 es menor, igual o mayor que s2 respectivamente.*/




#endif
