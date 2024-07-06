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

void find_player_position(t_game *game, int *player_x, int *player_y)
{
	int y;
	int x;

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
				return;
			}
			x++;
		}
		y++;
	}
	error_exit("Error: Player position not found");
}

void handle_move(t_game *game, int old_x, int old_y, int new_x, int new_y)
{
	char tmp;

	tmp = game->map[new_y][new_x];
	if (tmp != '1')
	{
		if (tmp == 'C')
		{
			game->collected_items++;
			game->map[new_y][new_x] = 'P';
		}
		else if (tmp == 'E')
		{
			if (game->collected_items == game->total_items)
			{
				printf("Congratulations! You collected all items and exited the game.\n");
				mlx_destroy_window(game->mlx, game->win);
				exit(0);
			}
			else
			{
				printf("You need to collect all items before exiting!\n");
				return;
			}
		}
		else
		{
			game->map[new_y][new_x] = 'P';
		}
		game->map[old_y][old_x] = '0';
		game->move_count++;
		printf("Moves: %d\n", game->move_count);
		render_map(game);
	}
}

void move_player(t_game *game, int new_x, int new_y)
{
	int old_x;
	int old_y;

	find_player_position(game, &old_x, &old_y);
	handle_move(game, old_x, old_y, new_x, new_y);
}

int key_press(int keycode, t_game *game)
{
	int player_x;
	int player_y;

	find_player_position(game, &player_x, &player_y);
	if (keycode == 65307)
	{
		mlx_destroy_window(game->mlx, game->win);
		exit(0);
	}
	else if (keycode == 119)
		move_player(game, player_x, player_y - 1);
	else if (keycode == 115)
		move_player(game, player_x, player_y + 1);
	else if (keycode == 97)
		move_player(game, player_x - 1, player_y);
	else if (keycode == 100)
		move_player(game, player_x + 1, player_y);
	return (0);
}

/*
** keycode == 65307  Escape key
** keycode == 119    W key
** keycode == 115    S key
** keycode == 97     A key
** keycode == 100    D key
*/