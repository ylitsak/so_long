NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLX42_FLAGS = -ldl -lglfw -pthread -lm
INCLUDE = -I ./libft -I ./MLX42/include/MLX42
SRCS = so_long.c check_map.c map_to_memory.c error_message.c utility_functions.c parse_map.c \
		validate_map_path.c game_graphics.c handle_keypress.c
OBJS = $(SRCS:.c=.o)
LIBFT = ./libft/libft.a
MLX42 = ./MLX42/build/libmlx42.a

all: $(NAME)


$(LIBFT):
	@$(MAKE) -C ./libft

$(MLX42):
	cd MLX42 && cmake -B build
	cd MLX42 && cmake --build build -j4
	@$(MAKE) -C MLX42/build -j4

$(NAME): $(OBJS) $(LIBFT) $(MLX42)
	$(CC) -o $(NAME) $(OBJS) $(LIBFT) $(MLX42) $(MLX42_FLAGS)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm -f $(OBJS)
	@$(MAKE) clean -C ./libft
	@$(MAKE) clean -C ./MLX42/build

fclean: clean
	rm -f $(NAME) $(LIBFT)
	@$(MAKE) fclean -C ./libft
	@$(MAKE) clean -C ./MLX42/build

re: fclean all

.PHONY: clean fclean re all