/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcools <gcools@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 15:30:36 by gcools            #+#    #+#             */
/*   Updated: 2026/04/16 12:26:42 by gcools           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

size_t  ft_strlen(const char *str);
char    *ft_strcpy(char *dest, const char *str);
int     ft_strcmp(char *s1, char *s2);
ssize_t ft_write(int fd, char *str,size_t lenght);
ssize_t ft_read(int fd, void *buf,size_t lenght);
char    *ft_strdup(const char *s);

int main(void)
{
    char    *str = "Hello, World!";
    char    dest[50];
    char    *s1 = "tesa";
    char    *s2 = "test";
    //char    buf[100];
    //char    my_buf[100];
    //ssize_t ret;
    //ssize_t my_ret;

    printf("--------------------------------\n");

    printf("ft_strlen : %zu\n", ft_strlen(str));
    printf("strlen : %zu\n", strlen(str));
    
    printf("--------------------------------\n");
    
    printf("ft_strcpy : %s\n", ft_strcpy(dest, str));
    printf("strcpy : %s\n", strcpy(dest, str));
    
    printf("--------------------------------\n");
    
    printf("ft_strcmp : %d\n", ft_strcmp(s1, s2));
    printf("strcmp : %d\n", strcmp(s1, s2));
    
    printf("--------------------------------\n");
    
    printf("\nft_write: %ld\n", ft_write(-1, "test", 5));
    printf("errno ft_write: %d\n", errno);
    printf("\nwrite : %ld\n", write(-1, "test", 5));
    printf("errno write: %d\n", errno);
    /*
    printf("--------------------------------\n");
    
    // Lecture normale depuis stdin
    printf("Ecris quelque chose : \n");
    ret = ft_read(0, buf, 100);
    my_ret = read(0, my_buf, 100);
    printf("ft_read retourne : %ld\n", ret);
    printf("ft_read lu : %s\n", buf);
    
    printf("read retourne : %ld\n", my_ret);
    printf("read lu : %s\n", my_buf);
    
    printf("Test d'erreur\n");
    
    // Erreur avec fd invalide
    ret = ft_read(-1, my_buf, 100);
    printf("ft_read erreur : %ld\n", my_ret);
    printf("errno : %d\n", errno);
    
    // Comparaison avec le vrai read
    ret = read(-1, buf, 100);
    printf("read erreur : %ld\n", ret);
    printf("errno : %d\n", errno);
    
    */
    printf("--------------------------------\n");
    
    printf("ft_strdup : %s\n", ft_strdup(str));
    printf("strdup : %s\n", strdup(str));
    
    printf("--------------------------------\n");

    return (0);
}
