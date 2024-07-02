# Makefile

NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iincludes
SRCS = src/main.c src/game.c src/graphics.c src/map.c
OBJS = $(SRCS:.c=.o)

# Paths
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
MLX = -Lminilibx-linux -lmlx -lXext -lX11 -lm

# Rule to build object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to build the libft library
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(MLX)

all: $(LIBFT) $(NAME)

clean:
	@rm -f $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
