#include "../includes/so_long.h"

void	init_game(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "so_long");
	mlx_key_hook(game->win, key_press, game);
    // Load textures, initialize game state, etc.
}