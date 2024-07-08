/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtcza <mwojtcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 16:08:02 by mwojtcza          #+#    #+#             */
/*   Updated: 2024/07/07 16:08:02 by mwojtcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	error_exit(const char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

int	close_window(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
	return (0);
}

void	find_player_position(t_game *game, int *player_x, int *player_y)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] == 'P')
			{
				*player_x = x;
				*player_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
	error_exit("Error: Player position not found");
}

int	process_line_width(char *line, t_game *game)
{
	int	width;

	width = ft_strlen(line) - 2;
	if (line[width - 1] == '\n')
		width--;
	if (game->width == 0)
		game->width = width;
	else if (width != game->width)
		return (-1);
	return (0);
}
