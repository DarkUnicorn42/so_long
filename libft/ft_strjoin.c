/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtcza <mwojtcza@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:58:40 by mwojtcza          #+#    #+#             */
/*   Updated: 2024/03/07 13:49:45 by mwojtcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*ptr;

	i = 0;
	j = 0;
	ptr = (char *) malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!ptr)
		return (NULL);
	while (s1[i])
	{
		ptr[j++] = s1[i++];
	}
	i = 0;
	while (s2[i])
	{
		ptr[j++] = s2[i++];
	}
	ptr[j] = '\0';
	return (ptr);
}
/*
#include <stdio.h>
#include <stdlib.h>

// Function declaration for ft_strjoin
char    *ft_strjoin(char const *s1, char const *s2);

int main() {
    // Example strings
    char const *s1 = "Hello, ";
    char const *s2 = "world!";

    // Call ft_strjoin to concatenate s1 and s2
    char *result = ft_strjoin(s1, s2);

    // Check if result is not NULL (memory allocation successful)
    if (result != NULL) {
        // Print the concatenated string
        printf("Concatenated string: %s\n", result);

        // Free the memory allocated for result
        free(result);
    } else {
        // Print an error message if memory allocation failed
        printf("Memory allocation failed.\n");
    }

    return 0;
}
*/
