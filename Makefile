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
CFLAGS = -Wall -Wextra -Werror -I./include/

MLXFLAGSO = -I/usr/include -Imlx_linux -O3
MLXFLAGSN = -Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -D LINUX -no-pie

LIBFT_DIR = libft/
MLX_DIR = mlx_linux/
UTILS_DIR = src/utils/

FILES = \
		src/game.c \
		src/graphics.c \
		src/so_long.c \
		src/map.c \
		src/utils.c \

OBJS = ${FILES:.c=.o}

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(MLXFLAGSO) -c $< -o ${<:.c=.o}

compile_dep:
	@make -C $(MLX_DIR)
	@cp $(MLX_DIR)/libmlx.a .
	@cp $(MLX_DIR)/libmlx_Linux.a .
	@mv $(MLX_DIR)/libmlx.a .
	@mv $(MLX_DIR)/libmlx_Linux.a .
	@make -C $(LIBFT_DIR)
	@cp $(LIBFT_DIR)/libft.a .
	@mv $(LIBFT_DIR)/libft.a .
	echo "\n\n" $(OBJS) "\n\n"

$(NAME): compile_dep $(OBJS)
	$(CC) $(CFLAGS) $(MLXFLAGSN) $(OBJS) libft.a libmlx.a libmlx_Linux.a -o $(NAME)


clean:
	rm -f $(OBJS)
	@make -C $(LIBFT_DIR) clean
	@make -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	rm -f libmlx.a
	rm -f libmlx_Linux.a
	rm -f libft.a

re: all

.PHONY: all clean fclean re