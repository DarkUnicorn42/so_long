
#include "../includes/so_long.h"

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