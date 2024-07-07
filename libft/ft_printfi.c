/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtcza <mwojtcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:27:24 by mwojtcza          #+#    #+#             */
/*   Updated: 2024/07/07 17:02:10 by mwojtcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printfi(int n, int *len)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		(*len) += 11;
		return ;
	}
	else if (n < 0)
	{
		ft_printfc('-', len);
		ft_printfi(-n, len);
	}
	else
	{
		if (n > 9)
			ft_printfi(n / 10, len);
		ft_printfc(n % 10 + '0', len);
	}
}
