/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtcza <mwojtcza@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 20:20:36 by mwojtcza          #+#    #+#             */
/*   Updated: 2024/03/08 12:27:28 by mwojtcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	cc;

	str = (unsigned char *) s;
	cc = (unsigned char) c;
	i = 0;
	while (i < n)
	{
		if (str[i] == cc)
		{
			return ((void *) &str[i]);
		}
		i++;
	}
	return (NULL);
}
/*
#include <string.h>
#include <stdio.h>
int	main(void)
{
	char	str[10] = "abcdefg";
	char	c;
	c = 'c';

	printf("searched place is %p\n", ft_memchr(str, c, 10));
}
*/
