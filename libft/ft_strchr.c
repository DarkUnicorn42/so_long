/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtcza <mwojtcza@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 12:18:12 by mwojtcza          #+#    #+#             */
/*   Updated: 2024/03/08 14:48:29 by mwojtcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (char) c)
		return ((char *) &s[i]);
	return (0);
}

/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	char	str[10] = "abcd";
	int	c;

	c = 'd';

	printf("pointer to %s\n ", ft_strchr(str, c));
}
*/
