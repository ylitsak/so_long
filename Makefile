NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLX42_FLAGS = -ldl -lglfw -pthread -lm
INCLUDE = -I ./libft -I ./MLX42/include/MLX42
SRCS = so_long.c check_map.c map_to_memory.c error_message.c utility_functions.c parse_map.c \
		validate_map_path.c
OBJS = $(SRCS:.c=.o)
LIBFT = ./libft/libft.a
LIBMLX = ./MLX42
MLXBUILD = ./MLX42/build/libmlx42.a

all: libmlx $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

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
	@$(MAKE) clean -C ./MLX42/build

fclean: clean
	rm -f $(NAME) $(LIBFT)
	@$(MAKE) fclean -C ./libft

re: fclean all

.PHONY: clean fclean re all