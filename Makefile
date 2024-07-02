# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mwojtcza <mwojtcza@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/02 14:05:28 by mwojtcza          #+#    #+#              #
#    Updated: 2024/07/02 14:05:28 by mwojtcza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = clang
CFLAGS = -Wall -Wextra -Werror -Iincludes
SRCS = src/main.c src/game.c src/graphics.c src/map.c
OBJS = $(SRCS:.c=.o)

# Paths
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
MLX_DIR = mlx_linux
MLX_LIB = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -Lmlx_linux -L/usr/lib -Imlx_linux -lmlx -lXext -lX11 -lm -lz -D LINUX -no-pie

# Rule to build object files
%.o: %.c
	$(CC) $(CFLAGS) $(MLX_FLAGS) -c $< -o $@

# Rule to build the libft library
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# Rule to build the MiniLibX library
$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR)

comp_libs:
	@make -C $(LIBFT)
	@make -C $(MLX_DIR)

$(NAME): comp_libs $(OBJS)
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJS) $(LIBFT) $(MLX_LIB) -o $(NAME)

all: $(NAME)

clean:
	@rm -f $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(MLX_DIR) clean

re: fclean all

.PHONY: all clean fclean re