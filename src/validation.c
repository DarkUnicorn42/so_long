/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtcza <mwojtcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 16:08:14 by mwojtcza          #+#    #+#             */
/*   Updated: 2024/07/07 16:08:14 by mwojtcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	count_in_row(char *row, int width, t_game *game)
{
	int	col;

	col = 0;
	while (col < width)
	{
		if (row[col] == 'C')
			game->coins++;
		else if (row[col] == 'E')
			game->exits++;
		else if (row[col] == 'P')
			game->player++;
		col++;
	}
}

void	count_elements(t_game *game)
{
	int	row;

	game->coins = 0;
	game->exits = 0;
	game->player = 0;
	row = 0;
	while (row < game->height)
	{
		count_in_row(game->map[row], game->width, game);
		row++;
	}
	if (game->coins == 0)
		error_exit("Error: No coins found on the map");
	if (game->exits != 1)
		error_exit("Error: There must be exactly one exit on the map");
	if (game->player != 1)
		error_exit("Error: There must be exactly one player on the map");
	game->total_items = game->coins;
}

void	check_walls(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->width)
	{
		if (game->map[0][i] != '1')
			error_exit("Error: Walls at the first row");
		if (game->map[game->height - 1][i] != '1')
			error_exit("Error: Walls at the last row");
		i++;
	}
	i = 0;
	while (i < game->height)
	{
		if (game->map[i][0] != '1')
			error_exit("Error: Walls at the first column, width");
		if (game->map[i][game->width - 1] != '1')
			error_exit("Error: Walls at the last column");
		i++;
	}
}
