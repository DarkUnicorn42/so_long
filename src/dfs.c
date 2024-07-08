/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtcza <mwojtcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 15:57:28 by mwojtcza          #+#    #+#             */
/*   Updated: 2024/07/07 15:57:28 by mwojtcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/* v = visited */
void	dfs(int **v, int x, int y, t_game *game)
{
	int	a;
	int	b;

	a = game->height;
	b = game->width;
	if (x < 0 || x >= b || y < 0 || y >= a || game->map[y][x] == '1' || v[y][x])
		return ;
	v[y][x] = 1;
	dfs(v, x + 1, y, game);
	dfs(v, x - 1, y, game);
	dfs(v, x, y + 1, game);
	dfs(v, x, y - 1, game);
}

int	**init_visited(int width, int height)
{
	int	**visited;
	int	i;
	int	j;

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

void	free_visited(int **visited, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(visited[i]);
		i++;
	}
	free(visited);
}

/*v = visited*/
void	validate_reach(t_game *game, int **v)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if ((game->map[i][j] == 'C' || game->map[i][j] == 'E') && !v[i][j])
			{
				free_visited(v, game->height);
				error_exit("Error: Not all coins and the exit are reachable");
			}
			j++;
		}
		i++;
	}
}

void	validate_paths(t_game *game)
{
	int	start_x;
	int	start_y;
	int	**visited;

	start_x = -1;
	start_y = -1;
	find_player_position(game, &start_x, &start_y);
	visited = init_visited(game->width, game->height);
	dfs(visited, start_x, start_y, game);
	validate_reach(game, visited);
	free_visited(visited, game->height);
}
