#include "../include/so_long.h"

void count_elements_in_row(char *row, int width, int *collectibles, int *exits, int *players)
{
	int col = 0;

	while (col < width)
	{
		if (row[col] == 'C')
			(*collectibles)++;
		else if (row[col] == 'E')
			(*exits)++;
		else if (row[col] == 'P')
			(*players)++;
		col++;
	}
}

void count_elements(t_game *game)
{
	int	row;
	int	collectibles;
	int	exits;
	int	players;

	collectibles = 0;
	exits = 0;
	players = 0;
	row = 0;
	while (row < game->height)
	{
		count_elements_in_row(game->map[row], game->width, &collectibles, &exits, &players);
		row++;
	}
	if (collectibles == 0)
		error_exit("Error: No collectibles found on the map");
	if (exits != 1)
		error_exit("Error: There must be exactly one exit on the map");
	if (players != 1)
		error_exit("Error: There must be exactly one player on the map");
	game->total_items = collectibles;
}

void	check_walls(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->width)
	{
		if (game->map[0][i] != '1')
			error_exit("Error: Map is not enclosed with walls at the first row");
		if (game->map[game->height - 1][i] != '1')
			error_exit("Error: Map is not enclosed with walls at the last row");
		i++;
	}
	i = 0;
	while (i < game->height)
	{
		if (game->map[i][0] != '1')
			error_exit("Error: Map is not enclosed with walls at the first column, width");
		if (game->map[i][game->width - 1] != '1')
			error_exit("Error: Map is not enclosed with walls at the last column");
		i++;
	}
}
