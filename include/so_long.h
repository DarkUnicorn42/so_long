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
	int		coins;
	int		exits;
	int		player;
}	t_game;

/* Game */
void	init_game(t_game *game);
void	*xpm_to_img(t_game *game, char *path);
void	load_textures(t_game *game);
int		key_press(int keycode, t_game *game);

/* Graphics */
void	put_image_to_window(t_game *game, void *img, int x, int y);
void	render_map(t_game *game);
void	handle_move(t_game *game, int new_x, int new_y);
int		handle_exit(t_game *game);

/* Map */
int		set_height_width(int fd, t_game *game);
int		get_map_dimensions(const char *file, t_game *game);
void	init_map_memory(t_game *game);
void	close_and_validate_map(int fd, t_game *game);
int		parse_map(const char *file, t_game *game);

/* Utils */
void	error_exit(const char *msg);
int		close_window(t_game *game);
void	find_player_position(t_game *game, int *player_x, int *player_y);
int		process_line_width(char *line, t_game *game);

/* Validation */
void	count_in_row(char *row, int width, t_game *game);
void	count_elements(t_game *game);
void	check_walls(t_game *game);

/* DFS */
void	dfs(int **v, int x, int y, t_game *game);
int		**init_visited(int width, int height);
void	free_visited(int **visited, int height);
void	validate_reach(t_game *game, int **v);
void	validate_paths(t_game *game);

#endif
