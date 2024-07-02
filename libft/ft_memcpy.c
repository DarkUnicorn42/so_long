/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtcza <mwojtcza@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:43:30 by mwojtcza          #+#    #+#             */
/*   Updated: 2024/03/03 14:03:35 by mwojtcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dest && !src)
	{
		return (0);
	}
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}

/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	const char	src[50] = "halo";
	char		dest[50];
//	src[50] = "blablablabla";
	strcpy(dest,"hello");
	printf("test1 %s\n", dest);
	ft_memcpy(dest, src, strlen(src)+1);
	printf("test2 %s\n", dest);

	return (0);
}
*/
