/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcools <gcools@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 15:30:36 by gcools            #+#    #+#             */
/*   Updated: 2026/04/20 12:05:43 by gcools           ###   ########.fr       */
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
    char    buf[100];
    ssize_t ret;
    char    *dup;

    // ===== FT_STRLEN =====
    printf("========== FT_STRLEN ==========\n");
    printf("ft_strlen(\"Hello, World!\") : %zu\n", ft_strlen(str));
    printf("strlen(\"Hello, World!\")    : %zu\n", strlen(str));
    printf("ft_strlen(\"\")              : %zu\n", ft_strlen(""));
    printf("strlen(\"\")                 : %zu\n", strlen(""));
    printf("ft_strlen(\"a\")             : %zu\n", ft_strlen("a"));
    printf("strlen(\"a\")                : %zu\n", strlen("a"));

    // ===== FT_STRCPY =====
    printf("\n========== FT_STRCPY ==========\n");
    printf("ft_strcpy(dest, \"Hello, World!\") : %s\n", ft_strcpy(dest, str));
    printf("strcpy(dest, \"Hello, World!\")    : %s\n", strcpy(dest, str));
    printf("ft_strcpy(dest, \"\")              : [%s]\n", ft_strcpy(dest, ""));
    printf("strcpy(dest, \"\")                 : [%s]\n", strcpy(dest, ""));
    printf("ft_strcpy(dest, \"a\")             : %s\n", ft_strcpy(dest, "a"));
    printf("strcpy(dest, \"a\")                : %s\n", strcpy(dest, "a"));

    // ===== FT_STRCMP =====
    printf("\n========== FT_STRCMP ==========\n");
    printf("ft_strcmp(\"tesa\", \"test\") : %d\n", ft_strcmp("tesa", "test"));
    printf("strcmp(\"tesa\", \"test\")    : %d\n", strcmp("tesa", "test"));
    printf("ft_strcmp(\"test\", \"test\") : %d\n", ft_strcmp("test", "test"));
    printf("strcmp(\"test\", \"test\")    : %d\n", strcmp("test", "test"));
    printf("ft_strcmp(\"test\", \"tesa\") : %d\n", ft_strcmp("test", "tesa"));
    printf("strcmp(\"test\", \"tesa\")    : %d\n", strcmp("test", "tesa"));
    printf("ft_strcmp(\"\", \"\")          : %d\n", ft_strcmp("", ""));
    printf("strcmp(\"\", \"\")             : %d\n", strcmp("", ""));

    // ===== FT_WRITE =====
    printf("\n========== FT_WRITE ==========\n");

    // Test sur stdout
    printf("ft_write sur stdout : ");
    ret = ft_write(1, "Hello from ft_write!\n", 21);
    printf("ft_write retourne   : %ld\n", ret);

    printf("write sur stdout    : ");
    ret = write(1, "Hello from write!\n", 18);
    printf("write retourne      : %ld\n", ret);

    // Test erreur fd invalide
    ret = ft_write(-1, "test", 4);
    printf("ft_write fd=-1      : %ld | errno : %d\n", ret, errno);
    ret = write(-1, "test", 4);
    printf("write fd=-1         : %ld | errno : %d\n", ret, errno);

    // ===== FT_READ =====
    printf("\n========== FT_READ ==========\n");

    // Test lecture normale
    printf("Ecris quelque chose pour ft_read : ");
    fflush(stdout);
    memset(buf, 0, 100);
    ret = ft_read(0, buf, 100);
    printf("ft_read retourne : %ld\n", ret);
    printf("ft_read lu       : %s\n", buf);

    printf("Ecris quelque chose pour read    : ");
    fflush(stdout);
    memset(buf, 0, 100);
    ret = read(0, buf, 100);
    printf("read retourne    : %ld\n", ret);
    printf("read lu          : %s\n", buf);

    // Test erreur fd invalide
    ret = ft_read(-1, buf, 100);
    printf("ft_read fd=-1    : %ld | errno : %d\n", ret, errno);
    ret = read(-1, buf, 100);
    printf("read fd=-1       : %ld | errno : %d\n", ret, errno);

    // ===== FT_STRDUP =====
    printf("\n========== FT_STRDUP ==========\n");

    // Test normal
    dup = ft_strdup(str);
    printf("ft_strdup(\"%s\") : %s\n", str, dup);
    free(dup);

    dup = strdup(str);
    printf("strdup(\"%s\")    : %s\n", str, dup);
    free(dup);

    // Test chaine vide
    dup = ft_strdup("");
    printf("ft_strdup(\"\")   : [%s]\n", dup);
    free(dup);

    dup = strdup("");
    printf("strdup(\"\")      : [%s]\n", dup);
    free(dup);

    // Test chaine d'un seul caractere
    dup = ft_strdup("a");
    printf("ft_strdup(\"a\")  : %s\n", dup);
    free(dup);

    dup = strdup("a");
    printf("strdup(\"a\")     : %s\n", dup);
    free(dup);

    printf("\n================================\n");
    return (0);
}