/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtcza <mwojtcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 14:05:11 by mwojtcza          #+#    #+#             */
/*   Updated: 2024/07/02 14:05:11 by mwojtcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	get_map_dimensions(const char *file, t_game *game)
{
	int		fd;
	char	*line;
	int		width;
	int		height;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		error_exit("Error opening map file");
	height = 0;
	game->width = 0;
	while ((line = get_next_line(fd)))
	{
		width = ft_strlen(line) - 2;
		if (line[width - 1] == '\n')
			width--;
		if (game->width == 0)
			game->width = width;
		else if (width != game->width)
		{
			printf("Mismatched line width: expected %d, got %d\n", game->width, width);
			free(line);
			close(fd);
			return (-1);
		}
		height++;
		free(line);
	}
	close(fd);
	game->height = height;
	if (game->height == 0 || game->width == 0)
		error_exit("Error: Empty or invalid map");
	return (0);
}

void	count_elements(t_game *game)
{
	int	row;
	int	col;
	int	collectibles;
	int	exits;
	int	players;

	collectibles = 0;
	exits = 0;
	players = 0;
	row = 0;
	while (row < game->height)
	{
		col = 0;
		while (col < game->width)
		{
			if (game->map[row][col] == 'C')
				collectibles++;
			else if (game->map[row][col] == 'E')
				exits++;
			else if (game->map[row][col] == 'P')
				players++;
			col++;
		}
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

int	parse_map(const char *file, t_game *game)
{
	int		fd;
	char	*line;
	int		row;

	if (get_map_dimensions(file, game) == -1)
		return (-1);
	game->map = (char **)malloc(sizeof(char *) * (game->height + 1));
	if (!game->map)
		error_exit("Error allocating memory for map");
	fd = open(file, O_RDONLY);
	if (fd < 0)
		error_exit("Error opening map file");
	row = 0;
	while ((line = get_next_line(fd)))
	{
		game->map[row] = ft_strtrim(line, "\n");
		if (!game->map[row])
			error_exit("Error duplicating map line");
		free(line);
		row++;
	}
	game->map[row] = NULL;
	close(fd);

	count_elements(game);
	check_walls(game);

	return (0);
}
