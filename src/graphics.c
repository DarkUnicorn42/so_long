/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtcza <mwojtcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 14:05:15 by mwojtcza          #+#    #+#             */
/*   Updated: 2024/07/02 14:05:15 by mwojtcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/so_long.h"

int	key_press(int keycode, t_game *game)
{
	if (keycode == 65307) // Escape key
	{
		mlx_destroy_window(game->mlx, game->win);
		exit(0);
	}
	// Handle other key events (W, A, S, D or arrow keys)
	return (0);
}