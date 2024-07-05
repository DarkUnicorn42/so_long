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

void	move_player(t_game *game, int new_x, int new_y)
{
	int		old_x;
	int		old_y;
	char	tmp;

	old_y = 0;
	while (old_y < game->height)
	{
		old_x = 0;
		while (old_x < game->width)
		{
			if (game->map[old_y][old_x] == 'P')
			{
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
				return;
			}
			old_x++;
		}
		old_y++;
	}
}

int	key_press(int keycode, t_game *game)
{
	int		player_x;
	int		player_y;

	player_x = -1;
	player_y = -1;
	for (int y = 0; y < game->height; y++)
	{
		for (int x = 0; x < game->width; x++)
		{
			if (game->map[y][x] == 'P')
			{
				player_x = x;
				player_y = y;
				break;
			}
		}
		if (player_x != -1 && player_y != -1)
			break;
	}
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