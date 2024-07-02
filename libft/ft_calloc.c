/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtcza <mwojtcza@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 14:00:39 by mwojtcza          #+#    #+#             */
/*   Updated: 2024/03/08 15:06:36 by mwojtcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmeb, size_t size)
{
	void	*tmp;

	if (size >= 2147483647 || nmeb >= 2147483647)
	{
		if (size != 0 && nmeb != 0)
			return (NULL);
	}
	tmp = malloc(nmeb * size);
	if (!tmp)
	{
		return (NULL);
	}
	ft_bzero(tmp, nmeb * size);
	return (tmp);
}
/*
#include <stdio.h>
#include <stdlib.h>

int	main(void) {
	
	int *ptr;
	int num_elements = 5;

    // Allocate memory for 5 integers, initialized to zero
	ptr = (int *)ft_calloc(num_elements, sizeof(int));

	if (ptr == NULL)
	{
        	printf("Memory allocation failed\n");
	return 1;
	}
    // Use the allocated memory
	printf("Memory allocated successfully:\n");
	for (int i = 0; i < num_elements; i++)
	{
		printf("ptr[%d] = %d\n", i, ptr[i]);  // Will print 0 for each element
	}
    // Free the allocated memory
	free(ptr);
	return 0;
}
*/
