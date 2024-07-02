/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtcza <mwojtcza@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:36:24 by mwojtcza          #+#    #+#             */
/*   Updated: 2024/03/09 18:33:57 by mwojtcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*d;
	char		*s;

	i = 0;
	if (!dest && !src)
	{
		return (0);
	}
	d = (char *)dest;
	s = (char *)src;
	if (d > s)
		while (n-- > 0)
			d[n] = s[n];
	else
	{
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dest);
}
/*
#include <string.h>
#include <stdio.h>
int	main(void)
{
	//char	str[10] = "aabbcc";
	char	str1[10] = "aabbcc";
	//printf("dest  = %s\n", dest);
	//printf("dest2  = %s\n", dest2);
	//memmove(dest, str, 4);
	//memmove(dest2, str, 4);
	//printf("dest after = %s\n", dest);
	//printf("dest2 after = %s\n", dest2);
	
	//printf("string = %s\n", str);
	//memmove(str + 2, str, 4);
	//printf("string = %s\n", str);

	printf("string = %s\n", str1);
	ft_memmove(str1 + 2, str1, 4);
	printf("string = %s\n", str1);
}
*/
