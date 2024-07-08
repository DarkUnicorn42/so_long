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

int	key_press(int keycode, t_game *game)
{
	int		player_x;
	int		player_y;

	find_player_position(game, &player_x, &player_y);
	if (keycode == 65307)
	{
		mlx_destroy_window(game->mlx, game->win);
		exit(0);
	}
	else if (keycode == 119)
		handle_move(game, player_x, player_y - 1);
	else if (keycode == 115)
		handle_move(game, player_x, player_y + 1);
	else if (keycode == 97)
		handle_move(game, player_x - 1, player_y);
	else if (keycode == 100)
		handle_move(game, player_x + 1, player_y);
	return (0);
}

/*
** keycode == 65307  Escape key
** keycode == 119    W key
** keycode == 115    S key
** keycode == 97     A key
** keycode == 100    D key
*/
/*
** x = width
** y = height
*/

void	*xpm_to_img(t_game *game, char *path)
{
	int		x;
	int		y;
	void	*p;

	p = mlx_xpm_file_to_image(game->mlx, path, &x, &y);
	return (p);
}

void	load_textures(t_game *game)
{
	game->img_wall = xpm_to_img(game, "./textures/wall.xpm");
	if (!game->img_wall)
		error_exit("Error loading wall texture");
	game->img_floor = xpm_to_img(game, "./textures/bg.xpm");
	if (!game->img_floor)
		error_exit("Error loading floor texture");
	game->img_collect = xpm_to_img(game, "./textures/coin.xpm");
	if (!game->img_collect)
		error_exit("Error loading collectible texture");
	game->img_exit = xpm_to_img(game, "./textures/exit.xpm");
	if (!game->img_exit)
		error_exit("Error loading exit texture");
	game->img_exit_open = xpm_to_img(game, "./textures/exit_open.xpm");
	if (!game->img_exit_open)
		error_exit("Error loading open exit texture");
	game->img_player = xpm_to_img(game, "./textures/player.xpm");
	if (!game->img_player)
		error_exit("Error loading player texture");
}

void	init_game(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		error_exit("Error initializing MLX");
	game->win = mlx_new_window(game->mlx, game->width * 100,
			game->height * 100, "so_long");
	if (!game->win)
		error_exit("Error creating window");
	game->move_count = 0;
	game->collected_items = 0;
	load_textures(game);
	render_map(game);
	mlx_key_hook(game->win, key_press, game);
	mlx_hook(game->win, 17, 0, close_window, game);
}
