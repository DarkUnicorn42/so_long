/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtcza <mwojtcza@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:00:27 by mwojtcza          #+#    #+#             */
/*   Updated: 2024/03/09 20:51:37 by mwojtcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_word_countv2(char const *s, char c)
{
	int	count;
	int	inword;

	inword = 0;
	count = 0;
	while (*s)
	{
		if (*s != c && !inword)
		{
			count++;
			inword = 1;
		}
		else if (*s == c)
			inword = 0;
		s++;
	}
	return (count);
}

static void	*ft_free(char **strs, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char		**list;
	const char	*tmp;
	int			i;
	int			lenword;

	lenword = ft_word_countv2(s, c);
	list = (char **)malloc((lenword + 1) * sizeof(char *));
	if (!list)
		return (0);
	i = 0;
	while (i < lenword)
	{
		while (*s == c && *s)
			s++;
		tmp = s;
		while (*s && *s != c)
			s++;
		list[i] = ft_substr(tmp, 0, s - tmp);
		if (!list[i])
			return (ft_free(list, i));
		i++;
	}
	list[i] = NULL;
	return (list);
}

/*
#include <stdio.h> // for printf
#include <stdlib.h> // for free

int main(void)
{
    char const *s = "   asdf asdf     ";
    char c = 'x';
    char **result = ft_split(s, c);
    
    if (result)
    {
        for (int i = 0; result[i] != NULL; i++)
        {
            printf("%s\n", result[i]);
            free(result[i]); // Free memory allocated for each word
        }
        free(result); // Free memory allocated for the array of pointers
    }
    
    return 0;
}
*/
