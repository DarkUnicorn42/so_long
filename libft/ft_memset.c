/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtcza <mwojtcza@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 12:29:40 by mwojtcza          #+#    #+#             */
/*   Updated: 2024/03/08 12:20:52 by mwojtcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		ptr[i] = (unsigned char) c;
		i++;
	}
	return (s);
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char str[50];
	strcpy(str,"Hello World");
	puts(str);
	
	memset(str,'$',16);
	puts(str);

//	ft_memset(str,'$',16);
//	puts(str);
	
	return(0);
}
*/
