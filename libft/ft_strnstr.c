/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtcza <mwojtcza@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 20:51:31 by mwojtcza          #+#    #+#             */
/*   Updated: 2024/03/05 15:22:36 by mwojtcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (little[0] == 0)
	{
		return ((char *) big);
	}
	while (i < len && big[i])
	{
		while ((big[i + j] == little[j]) && big[i + j] && i + j < len)
		{
			j++;
			if (little[j] == 0)
			{
				return ((char *) big + i);
			}
		}
		i++;
		j = 0;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	const char	*largestring = "Foo Bar Baz";
	const char	*smallstring = "Bar";
	char		*ptr;

	ptr = ft_strnstr(largestring, smallstring, 10);
	printf("pointer %s\n", ptr);
}
*/
