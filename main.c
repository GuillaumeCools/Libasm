/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcools <gcools@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 15:30:36 by gcools            #+#    #+#             */
/*   Updated: 2026/04/13 15:33:44 by gcools           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

size_t  ft_strlen(const char *str);

int main(void)
{
    char *str = "Hello, World!";
    printf("ft_strlen : %zu\n", ft_strlen(str));
    printf("strlen : %zu\n", strlen(str));
    return (0);
}
