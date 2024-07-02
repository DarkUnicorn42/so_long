/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtcza <mwojtcza@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:01:41 by mwojtcza          #+#    #+#             */
/*   Updated: 2024/03/09 18:32:48 by mwojtcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countstr(int n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		count++;
		n = -n;
	}
	if (n == 0)
		count++;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	int				i;
	char			*str;
	long long		num;

	num = n;
	i = ft_countstr(num);
	str = (char *)malloc((sizeof(char) * (i + 1)));
	str[i--] = '\0';
	if (num < 0)
	{
		str[0] = '-';
		num = -num;
	}
	else if (num == 0)
	{
		str[0] = '0';
		return (str);
	}
	while (num != 0)
	{
		str[i--] = (num % 10) + '0';
		num /= 10;
	}
	return (str);
}
/*
#include <stdio.h> // for printf
#include <stdlib.h> // for free

int main(void)
{
    int num = -9992345; // Example number to convert

    char *result = ft_itoa(num);
    if (result != NULL) {
        printf("Result: %s\n", result);
        free(result); // Free memory allocated by ft_itoa
    } else {
        printf("Memory allocation failed.\n");
    }

    return 0;
}
*/
