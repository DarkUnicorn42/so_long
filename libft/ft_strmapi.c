/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtcza <mwojtcza@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 19:33:59 by mwojtcza          #+#    #+#             */
/*   Updated: 2024/03/08 12:00:03 by mwojtcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*ptr;

	ptr = malloc((ft_strlen(s) + 1) * sizeof(char));
	i = 0;
	if (!ptr)
		return (NULL);
	while (i < ft_strlen(s))
	{
		ptr[i] = (*f)(i, s[i]);
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
/*
#include <stdio.h>

// Prototype of the ft_strmapi function
char *ft_strmapi(char const *s, char (*f)(unsigned int, char));

// Example function that converts characters to uppercase
char uppercase(unsigned int i, char c) {
    if (c >= 'a' && c <= 'z') {
        return c - 'a' + 'A'; // Convert lowercase to uppercase
    } else {
        return c; // Leave other characters unchanged
    }
}

int main() {
    // Input string
    char input[] = "Hello, World!";

    // Call ft_strmapi to convert each character to uppercase
    char *result = ft_strmapi(input, &uppercase);

    // Print the result
    printf("Result: %s\n", result);

    // Free the memory allocated for the result
    free(result);

    return 0;
}
*/
