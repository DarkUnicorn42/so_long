#include "../include/so_long.h"

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

int **init_visited(int width, int height)
{
	int **visited;
	int i;
	int j;

	visited = (int **)malloc(sizeof(int *) * height);
	if (!visited)
		error_exit("Error: Memory allocation failed for visited array");
	i = 0;
	while (i < height)
	{
		visited[i] = (int *)malloc(sizeof(int) * width);
		if (!visited[i])
			error_exit("Error: Memory allocation failed for visited row");
		j = 0;
		while (j < width)
		{
			visited[i][j] = 0;
			j++;
		}
		i++;
	}
	return (visited);
}

void free_visited(int **visited, int height)
{
	int i;

	i = 0;
	while (i < height)
	{
		free(visited[i]);
		i++;
	}
	free(visited);
}

void validate_reach(t_game *game, int **visited)
{
	int i;
	int j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if ((game->map[i][j] == 'C' || game->map[i][j] == 'E') && !visited[i][j])
			{
				free_visited(visited, game->height);
				error_exit("Error: Not all coins and the exit are reachable");
			}
			j++;
		}
		i++;
	}
}

void validate_paths(t_game *game)
{
	int start_x;
	int start_y;
	int **visited;

	start_x = -1;
	start_y = -1;
	find_player_position(game, &start_x, &start_y);
	visited = init_visited(game->width, game->height);
	dfs(game->map, visited, start_x, start_y, game->width, game->height);
	validate_reach(game, visited);
	free_visited(visited, game->height);
}

/*

void validate_paths(t_game *game)
{
	int start_x;
	int start_y;

	start_x = -1;
	start_y = -1;
	find_player_position(game, &start_x, &start_y);
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
	dfs(game->map, visited, start_x, start_y, game->width, game->height);
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
	i = 0;
	while (i < game->height)
	{
		free(visited[i]);
		i++;
	}
	free(visited);
}
*/