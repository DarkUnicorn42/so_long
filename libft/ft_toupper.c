/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtcza <mwojtcza@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:24:39 by mwojtcza          #+#    #+#             */
/*   Updated: 2024/02/27 14:49:46 by mwojtcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c > 96 && c < 123)
	{
		c -= 32;
	}
	return (c);
}
/*
#include <stdio.h>
#include <unistd.h>

int	main(void)
{
//	write(1, ft_toupper("a"),1);
	printf("%c\n",ft_toupper('a'));
}
*/
