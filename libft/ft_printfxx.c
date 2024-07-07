/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfxx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtcza <mwojtcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:58:47 by mwojtcza          #+#    #+#             */
/*   Updated: 2024/07/07 17:02:21 by mwojtcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printfxx(unsigned int c, const char f, int *len)
{
	int			i;
	char		*base;
	char		str[13];

	i = 0;
	if (f == 'x')
		base = "0123456789abcdef";
	if (f == 'X')
		base = "0123456789ABCDEF";
	if (c == 0)
	{
		ft_printfc('0', len);
		return ;
	}
	while (c != 0)
	{
		str[i] = base[c % 16];
		c /= 16;
		i++;
	}
	while (i--)
		ft_printfc(str[i], len);
}
