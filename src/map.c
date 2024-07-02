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

int	parse_map(const char *file, t_game *game)
{
	int		fd;
	char	buffer[1024]; // Adjust buffer size as needed
	int		ret;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening map file");
		return (-1);
	}
	ret = read(fd, buffer, sizeof(buffer));
	if (ret < 0)
	{
		perror("Error reading map file");
		close(fd);
		return (-1);
	}
	buffer[ret] = '\0';
	close(fd);
	// Add logic to parse the map and initialize game variables
	(void)game; // Placeholder to avoid unused parameter warning
	return (0);
}