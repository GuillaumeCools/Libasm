/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaumecools <guillaumecools@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 15:30:36 by gcools            #+#    #+#             */
/*   Updated: 2026/04/20 11:55:45 by guillaumeco      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>

size_t  ft_strlen(const char *str);
char    *ft_strcpy(char *dest, const char *str);
int     ft_strcmp(char *s1, char *s2);
ssize_t ft_write(int fd, char *str, size_t length);
ssize_t ft_read(int fd, void *buf, size_t length);
char    *ft_strdup(const char *s);

int main(void)
{
    char    *str = "Hello, World!";
    char    dest[50];
    char    my_dest[50];
    char    *s1 = "tesa";
    char    *s2 = "test";
    char    *s3 = "test";
    char    *s4 = "test";
    char    buf[100];
    char    my_buf[100];
    ssize_t ret;
    ssize_t my_ret;
    char    *dup;
    char    *my_dup;

    // ===== ft_strlen =====
    printf("========== ft_strlen ==========\n");
    printf("ft_strlen(\"Hello, World!\") : %zu\n", ft_strlen(str));
    printf("strlen(\"Hello, World!\")    : %zu\n", strlen(str));
    printf("ft_strlen(\"\")              : %zu\n", ft_strlen(""));
    printf("strlen(\"\")                 : %zu\n", strlen(""));
    printf("ft_strlen(\"a\")             : %zu\n", ft_strlen("a"));
    printf("strlen(\"a\")                : %zu\n", strlen("a"));

    // ===== ft_strcpy =====
    printf("\n========== ft_strcpy ==========\n");
    printf("ft_strcpy(dest, \"Hello, World!\") : %s\n", ft_strcpy(dest, str));
    printf("strcpy(dest, \"Hello, World!\")    : %s\n", strcpy(my_dest, str));
    printf("ft_strcpy(dest, \"\")              : %s\n", ft_strcpy(dest, ""));
    printf("strcpy(dest, \"\")                 : %s\n", strcpy(my_dest, ""));

    // ===== ft_strcmp =====
    printf("\n========== ft_strcmp ==========\n");
    printf("ft_strcmp(\"tesa\", \"test\") : %d\n", ft_strcmp(s1, s2));
    printf("strcmp(\"tesa\", \"test\")    : %d\n", strcmp(s1, s2));
    printf("ft_strcmp(\"test\", \"test\") : %d\n", ft_strcmp(s3, s4));
    printf("strcmp(\"test\", \"test\")    : %d\n", strcmp(s3, s4));
    printf("ft_strcmp(\"test\", \"tesa\") : %d\n", ft_strcmp(s2, s1));
    printf("strcmp(\"test\", \"tesa\")    : %d\n", strcmp(s2, s1));
    printf("ft_strcmp(\"\", \"\")          : %d\n", ft_strcmp("", ""));
    printf("strcmp(\"\", \"\")             : %d\n", strcmp("", ""));

    // ===== ft_write =====
    printf("\n========== ft_write ==========\n");

    // Test normal sur stdout
    printf("ft_write sur stdout : ");
    ret = ft_write(1, "Hello from ft_write!\n", 21);
    printf("ft_write retourne   : %ld\n", ret);

    printf("write sur stdout    : ");
    my_ret = write(1, "Hello from write!\n", 18);
    printf("write retourne      : %ld\n", my_ret);

    // Test erreur fd invalide
    errno = 0;
    ret = ft_write(-1, "test", 5);
    printf("ft_write(-1) retourne : %ld\n", ret);
    printf("errno ft_write        : %d\n", errno);

    errno = 0;
    my_ret = write(-1, "test", 5);
    printf("write(-1) retourne    : %ld\n", my_ret);
    printf("errno write           : %d\n", errno);

    // ===== ft_read =====
    printf("\n========== ft_read ==========\n");

    // Test normal sur stdin
    printf("Ecris quelque chose pour ft_read : \n");
    ret = ft_read(0, buf, 100);
    buf[ret] = '\0';
    printf("ft_read retourne : %ld\n", ret);
    printf("ft_read lu       : %s\n", buf);

    printf("Ecris quelque chose pour read : \n");
    my_ret = read(0, my_buf, 100);
    my_buf[my_ret] = '\0';
    printf("read retourne    : %ld\n", my_ret);
    printf("read lu          : %s\n", my_buf);

    // Test erreur fd invalide
    errno = 0;
    ret = ft_read(-1, buf, 100);
    printf("ft_read(-1) retourne : %ld\n", ret);
    printf("errno ft_read        : %d\n", errno);

    errno = 0;
    my_ret = read(-1, my_buf, 100);
    printf("read(-1) retourne    : %ld\n", my_ret);
    printf("errno read           : %d\n", errno);

    // ===== ft_strdup =====
    printf("\n========== ft_strdup ==========\n");

    // Test normal
    dup = ft_strdup(str);
    my_dup = strdup(str);
    printf("ft_strdup(\"Hello, World!\") : %s\n", dup);
    printf("strdup(\"Hello, World!\")    : %s\n", my_dup);
    free(dup);
    free(my_dup);

    // Test chaine vide
    dup = ft_strdup("");
    my_dup = strdup("");
    printf("ft_strdup(\"\") : [%s]\n", dup);
    printf("strdup(\"\")    : [%s]\n", my_dup);
    free(dup);
    free(my_dup);

    // Test chaine d'un seul caractere
    dup = ft_strdup("a");
    my_dup = strdup("a");
    printf("ft_strdup(\"a\") : %s\n", dup);
    printf("strdup(\"a\")    : %s\n", my_dup);
    free(dup);
    free(my_dup);

    printf("\n================================\n");
    return (0);
}
