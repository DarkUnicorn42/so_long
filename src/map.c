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

int set_height_width(int fd, t_game *game)
{
	char	*line;
	int		width;
	int		height;

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
			return (-1);
		}
		height++;
		free(line);
	}
	game->height = height;
	return (0);
}

int get_map_dimensions(const char *file, t_game *game)
{
	int fd;
	int result;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		error_exit("Error opening map file");
	result = set_height_width(fd, game);
	close(fd);
	if (result == -1 || game->height == 0 || game->width == 0)
		error_exit("Error: Empty or invalid map");
	return (0);
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
	validate_paths(game);
	return (0);
}
