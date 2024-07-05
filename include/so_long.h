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

int		parse_map(const char *file, t_game *game);
void	init_game(t_game *game);
int		key_press(int keycode, t_game *game);
void	render_map(t_game *game);
int		get_map_dimensions(const char *file, t_game *game);
char	*get_next_line(int fd);
void	error_exit(const char *msg);
int		close_window(t_game *game);
void	check_walls(t_game *game);
void	count_elements(t_game *game);

#endif
