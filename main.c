/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcools <gcools@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 15:30:36 by gcools            #+#    #+#             */
/*   Updated: 2026/04/14 12:14:05 by gcools           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

size_t  ft_strlen(const char *str);
char    *ft_strcpy(char *dest, const char *str);
int     ft_strcmp(char *s1, char *s2);

int main(void)
{
    char    *str = "Hello, World!";
    char    dest[50];
    char    *s1 = "tesa";
    char    *s2 = "test";

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
    

    return (0);
}
