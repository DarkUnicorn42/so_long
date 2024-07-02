/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtcza <mwojtcza@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 15:32:39 by mwojtcza          #+#    #+#             */
/*   Updated: 2024/03/09 16:39:18 by mwojtcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;

	if (!s)
		return (0);
	if (ft_strlen(s) < start)
		len = 0;
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	ptr = malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (0);
	ft_strlcpy(ptr, s + start, len + 1);
	return (ptr);
}
/*
#include <stdio.h>
#include <stdlib.h>

// Prototype of the ft_substr function
char *ft_substr(char const *s, unsigned int start, size_t len);

int main() {
    char input[] = "Hello, World!";
    unsigned int start_index = 7; // Start extracting from index 7
    size_t length = 5; // Extract 5 characters

    // Call ft_substr function
    char *substring = ft_substr(input, start_index, length);

    if (substring) {
        printf("Substring: %s\n", substring);
        // Don't forget to free the allocated memory
        free(substring);
    } else {
        printf("Substring is NULL\n");
    }

    return 0;
}
*/
