/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtcza <mwojtcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 14:05:16 by mwojtcza          #+#    #+#             */
/*   Updated: 2024/07/02 14:05:16 by mwojtcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void load_textures(t_game *game)
{
	int img_width;
	int img_height;

	game->img_wall = mlx_xpm_file_to_image(game->mlx, "./textures/wall.xpm", &img_width, &img_height);
	if (!game->img_wall)
		error_exit("Error loading wall texture");
	game->img_floor = mlx_xpm_file_to_image(game->mlx, "./textures/bg.xpm", &img_width, &img_height);
	if (!game->img_floor)
		error_exit("Error loading floor texture");
	game->img_collect = mlx_xpm_file_to_image(game->mlx, "./textures/coin.xpm", &img_width, &img_height);
	if (!game->img_collect)
		error_exit("Error loading collectible texture");
	game->img_exit = mlx_xpm_file_to_image(game->mlx, "./textures/exit.xpm", &img_width, &img_height);
	if (!game->img_exit)
		error_exit("Error loading exit texture");
	game->img_exit_open = mlx_xpm_file_to_image(game->mlx, "./textures/exit_open.xpm", &img_width, &img_height);
	if (!game->img_exit_open)
		error_exit("Error loading open exit texture");
	game->img_player = mlx_xpm_file_to_image(game->mlx, "./textures/player.xpm", &img_width, &img_height);
	if (!game->img_player)
		error_exit("Error loading player texture");
}

void init_game(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		error_exit("Error initializing MLX");
	game->win = mlx_new_window(game->mlx, game->width * 100, game->height * 100, "so_long");
	if (!game->win)
		error_exit("Error creating window");
	game->move_count = 0;
	game->collected_items = 0;
	load_textures(game);
	render_map(game);
	mlx_key_hook(game->win, key_press, game);
	mlx_hook(game->win, 17, 0, close_window, game);
}
