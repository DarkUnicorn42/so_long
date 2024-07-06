/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtcza <mwojtcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 14:05:21 by mwojtcza          #+#    #+#             */
/*   Updated: 2024/07/02 14:05:21 by mwojtcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include "../libft/libft.h"

typedef struct s_game
{
	void	*mlx;
	void	*win;
	int		width;
	int		height;
	char	**map;
	int		move_count;
	int		total_items;
	int		collected_items;
	void	*img_wall;
	void	*img_floor;
	void	*img_collect;
	void	*img_exit;
	void	*img_exit_open;
	void	*img_player;
}	t_game;

/* Game */
void	init_game(t_game *game);
void	load_textures(t_game *game);
int		key_press(int keycode, t_game *game);

/* Graphics */
void	render_map(t_game *game);
void	handle_move(t_game *game, int old_x, int old_y, int new_x, int new_y);
void	move_player(t_game *game, int new_x, int new_y);
int		handle_exit(t_game *game);

/* Map */
int		set_height_width(int fd, t_game *game);
int		get_map_dimensions(const char *file, t_game *game);
int		parse_map(const char *file, t_game *game);

/* Utils */
void	error_exit(const char *msg);
int		close_window(t_game *game);
void	find_player_position(t_game *game, int *player_x, int *player_y);

/* Validation */
void	count_elements_in_row(char *row, int width, int *collectibles, int *exits, int *players);
void	count_elements(t_game *game);
void	check_walls(t_game *game);

/* DFS */
void	dfs(char **map, int **visited, int x, int y, int width, int height);
int		**init_visited(int width, int height);
void	free_visited(int **visited, int height);
void	validate_reach(t_game *game, int **visited);
void	validate_paths(t_game *game);

#endif
