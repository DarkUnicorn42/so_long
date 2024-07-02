/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtcza <mwojtcza@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 12:35:51 by mwojtcza          #+#    #+#             */
/*   Updated: 2024/03/09 18:34:29 by mwojtcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_totrim(char const *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static char	*ft_newstr(const char *s1, size_t start, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	if (len <= 0 || start >= ft_strlen(s1))
		return (ft_strdup(""));
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = s1[start + i];
		i++;
	}
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;

	i = 0;
	j = ft_strlen(s1) - 1;
	if (ft_strlen(s1) == 0)
		return (ft_strdup(""));
	while (ft_totrim(set, s1[i]))
		i++;
	while (ft_totrim(set, s1[j]))
		j--;
	if (i > j)
		return (ft_strdup(""));
	return (ft_newstr(s1, i, j - i + 1));
}
/*
#include <stdio.h>
#include <stdlib.h>

// Your ft_strtrim function here

int	main() 
{
    // Example usage of ft_strtrim
	char const	*s1 = "aaaahello worldaaaaa";
	char const	*set = "a"; // Set of characters to trim

	char	*trimmed = ft_strtrim(s1, set);
	if (trimmed)
       	{
		printf("Original string: \"%s\"\n", s1);
		printf("Trimmed string: \"%s\"\n", trimmed);
		free(trimmed); // Don't forget to free the allocated memory
	}
       	else
	{
		printf("Error: Failed to allocate memory\n");
	}
	return (0);
}
*/
