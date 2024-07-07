/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtcza <mwojtcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:27:28 by mwojtcza          #+#    #+#             */
/*   Updated: 2024/07/07 17:02:12 by mwojtcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printfp(unsigned long int c, int *len)
{
	char	str[25];
	char	*base;
	int		i;

	i = 0;
	base = "0123456789abcdef";
	if (c == 0)
	{
		write(1, "(nil)", 5);
		(*len) += 5;
		return ;
	}
	else
	{
		write(1, "0x", 2);
		(*len) += 2;
		while (c != 0)
		{
			str[i] = base[c % 16];
			c /= 16;
			i++;
		}
		while (i--)
			ft_printfc(str[i], len);
	}
}
