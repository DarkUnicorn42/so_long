/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtcza <mwojtcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 19:56:30 by mwojtcza          #+#    #+#             */
/*   Updated: 2024/03/14 12:34:21 by mwojtcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		(*f)(i, &s[i]);
		i++;
	}
}
/*
#include <stdio.h>

// Declaration of ft_striteri function
void ft_striteri(char *s, void (*f)(unsigned int, char*));

// Example function that prints the character and its index
void print_indexed_char(unsigned int index, char *c) {
    printf("Character at index %u: %c\n", index, *c);
}

int main() {
    // Example string
    char str[] = "Hello, world!";

    // Call ft_striteri with the example string
    ft_striteri(str, &print_indexed_char);

    return 0;
}
*/
