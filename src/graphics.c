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

void	render_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->img_wall, x * 100, y * 100);
			else if (game->map[y][x] == '0')
				mlx_put_image_to_window(game->mlx, game->win, game->img_floor, x * 100, y * 100);
			else if (game->map[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->img_collect, x * 100, y * 100);
			else if (game->map[y][x] == 'E')
			{
				if (game->collected_items == game->total_items)
					mlx_put_image_to_window(game->mlx, game->win, game->img_exit_open, x * 100, y * 100);
				else
					mlx_put_image_to_window(game->mlx, game->win, game->img_exit, x * 100, y * 100);
			}
			else if (game->map[y][x] == 'P')
				mlx_put_image_to_window(game->mlx, game->win, game->img_player, x * 100, y * 100);
			x++;
		}
		y++;
	}
}

int	handle_exit(t_game *game)
{
	if (game->collected_items == game->total_items)
	{
		printf("Congratulations! You win!\n");
		mlx_destroy_window(game->mlx, game->win);
		exit(0);
	}
	else
	{
		printf("You need to collect all items before exiting!\n");
		return (0);
	}
	return (1);
}

void	handle_move(t_game *game, int old_x, int old_y, int new_x, int new_y)
{
	char	tmp;

	tmp = game->map[new_y][new_x];
	if (tmp != '1')
	{
		if (tmp == 'C')
		{
			game->collected_items++;
			game->map[new_y][new_x] = 'P';
		}
		else if (tmp == 'E' && !handle_exit(game))
			return ;
		else
			game->map[new_y][new_x] = 'P';
		game->map[old_y][old_x] = '0';
		game->move_count++;
		printf("Moves: %d\n", game->move_count);
		render_map(game);
	}
}

void	move_player(t_game *game, int new_x, int new_y)
{
	int	old_x;
	int	old_y;

	find_player_position(game, &old_x, &old_y);
	handle_move(game, old_x, old_y, new_x, new_y);
}
