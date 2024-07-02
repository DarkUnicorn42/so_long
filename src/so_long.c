/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtcza <mwojtcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 14:05:13 by mwojtcza          #+#    #+#             */
/*   Updated: 2024/07/02 14:05:13 by mwojtcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		write(2, "Usage: ./so_long map.ber\n", 25);
		return (1);
	}
	if (parse_map(argv[1], &game) == -1)
	{
		write(2, "Error: Invalid map\n", 19);
		return (1);
	}
	init_game(&game);
	mlx_loop(game.mlx);
	return (0);
}