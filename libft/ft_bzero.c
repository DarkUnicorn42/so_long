/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtcza <mwojtcza@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 14:54:19 by mwojtcza          #+#    #+#             */
/*   Updated: 2024/03/07 16:31:08 by mwojtcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = s;
	i = 0;
	while (i < n)
	{
		ptr[i] = '\0';
		i++;
	}
}

/*
#include <string.h>
#include <stdio.h>
int	main(void)
{
	char str[50];
	strcpy(str, "This is a string");
	puts(str);
	bzero(str, 4);
	puts(str);
	ft_bzero(str, 4);
	puts(str);

	return (0);	
}
*/
