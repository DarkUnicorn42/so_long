

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

# define WIDTH 800
# define HEIGHT 600

typedef struct s_game
{
	void	*mlx;
	void	*win;
	// Add other game-related variables here
}	t_game;

int		parse_map(const char *file, t_game *game);
void	init_game(t_game *game);
int		key_press(int keycode, t_game *game);

#endif
