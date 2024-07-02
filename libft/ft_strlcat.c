/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtcza <mwojtcza@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 14:01:56 by mwojtcza          #+#    #+#             */
/*   Updated: 2024/03/08 14:55:54 by mwojtcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	srclen;
	size_t	dstlen;

	srclen = ft_strlen(src);
	dstlen = ft_strlen(dst);
	if (dstlen >= size)
		dstlen = size;
	if (dstlen == size)
		return (srclen + dstlen);
	if (srclen < size - dstlen)
		ft_memcpy(dst + dstlen, src, srclen + 1);
	else
	{
		ft_memcpy(dst + dstlen, src, size - dstlen -1);
		dst[size - 1] = '\0';
	}
	return (srclen + dstlen);
}
/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	char	str[] = "hello world and 42";
	char	buff[30];
	int	r;

	printf("String before = %s\n", str);
	r = ft_strlcat(buff, str, 5);
	printf("String after = %d\n", r);
}
*/
