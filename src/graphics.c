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

void put_image_to_window(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, img, x * 100, y * 100);
}

void render_map(t_game *game)
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
				put_image_to_window(game, game->img_wall, x, y);
			else if (game->map[y][x] == '0')
				put_image_to_window(game, game->img_floor, x, y);
			else if (game->map[y][x] == 'C')
				put_image_to_window(game, game->img_collect, x, y);
			else if (game->map[y][x] == 'E')
			{
				if (game->collected_items == game->total_items)
					put_image_to_window(game, game->img_exit_open, x, y);
				else
					put_image_to_window(game, game->img_exit, x, y);
			}
			else if (game->map[y][x] == 'P')
				put_image_to_window(game, game->img_player, x, y);
			x++;
		}
		y++;
	}
}

int	handle_exit(t_game *game)
{
	if (game->collected_items == game->total_items)
	{
		ft_printf("Congratulations! You win!\n");
		mlx_destroy_window(game->mlx, game->win);
		exit(0);
	}
	else
	{
		ft_printf("You need to collect all items before exiting!\n");
		return (0);
	}
	return (1);
}

void	handle_move(t_game *game, int new_x, int new_y)
{
	int old_x;
	int old_y;
	char tmp;

	find_player_position(game, &old_x, &old_y);
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
		ft_printf("Moves: %d\n", game->move_count);
		render_map(game);
	}
}
