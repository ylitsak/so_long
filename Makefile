NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLX42_FLAGS = -ldl -lglfw -pthread -lm
INCLUDE = -I ./libft -I ./MLX42/include/MLX42
SRCS = so_long.c check_map.c map_to_memory.c error_message.c utility_functions.c parse_map.c
OBJS = $(SRCS:.c=.o)
LIBFT = ./libft/libft.a
MLXBUILD = ./MLX42/build/libmlx42.a

all: $(NAME)

$(LIBFT):
	@$(MAKE) -C ./libft

$(MLXBUILD):
	@$(MAKE) -C ./MLX42

$(NAME): $(OBJS) $(LIBFT) $(MLXBUILD)
	$(CC) -o $(NAME) $(OBJS) $(LIBFT) $(MLXBUILD) $(MLX42_FLAGS) 

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm -f $(OBJS)
	@$(MAKE) clean -C ./libft
	@$(MAKE) clean -C ./MLX42

fclean: clean
	rm -f $(NAME) $(LIBFT) $(MLXBUILD)
	@$(MAKE) fclean -C ./libft
	@$(MAKE) fclean -C ./MLX42

re: fclean all

.PHONY: clean fclean re all