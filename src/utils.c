

#include "../include/so_long.h"

void	error_exit(const char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

int	close_window(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
	return (0);
}

void find_player_start(t_game *game, int *start_x, int *start_y)
{
	int y = 0;
	int x;

	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] == 'P')
			{
				*start_x = x;
				*start_y = y;
				return;
			}
			x++;
		}
		y++;
	}
	error_exit("Error: Player starting position not found");
}

void dfs(char **map, int **visited, int x, int y, int width, int height)
{
	if (x < 0 || x >= width || y < 0 || y >= height || map[y][x] == '1' || visited[y][x])
		return;

	visited[y][x] = 1;

	dfs(map, visited, x + 1, y, width, height);
	dfs(map, visited, x - 1, y, width, height);
	dfs(map, visited, x, y + 1, width, height);
	dfs(map, visited, x, y - 1, width, height);
}

void validate_paths(t_game *game)
{
	int start_x = -1;
	int start_y = -1;
	find_player_start(game, &start_x, &start_y);

	// Allocate visited array
	int **visited = (int **)malloc(sizeof(int *) * game->height);
	int i = 0;
	while (i < game->height)
	{
		visited[i] = (int *)malloc(sizeof(int) * game->width);
		int j = 0;
		while (j < game->width)
		{
			visited[i][j] = 0;
			j++;
		}
		i++;
	}

	// Perform DFS
	dfs(game->map, visited, start_x, start_y, game->width, game->height);

	// Validate all coins and the exit are reachable
	i = 0;
	while (i < game->height)
	{
		int j = 0;
		while (j < game->width)
		{
			if ((game->map[i][j] == 'C' || game->map[i][j] == 'E') && !visited[i][j])
			{
				int k = 0;
				while (k < game->height)
				{
					free(visited[k]);
					k++;
				}
				free(visited);
				error_exit("Error: Not all coins and the exit are reachable");
			}
			j++;
		}
		i++;
	}

	// Free visited array
	i = 0;
	while (i < game->height)
	{
		free(visited[i]);
		i++;
	}
	free(visited);
}


