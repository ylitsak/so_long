NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -I ./libft -I ./minilibx-linux
MLX = ./minilibx-linux/libmlx.a
X_LINK = -L/usr/X11/lib -lXext -lX11 -lm -lbsd
SRCS = so_long.c check_map.c map_to_memory.c error_message.c utility_functions.c parse_map.c
OBJS = $(SRCS:.c=.o)
LIBFT = ./libft/libft.a

all: $(NAME)

$(LIBFT):
	@$(MAKE) -C ./libft

$(NAME): $(OBJS) $(LIBFT)
	$(CC) -o $(NAME) $(OBJS) -L./libft -lft $(MLX) $(X_LINK)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm -f $(OBJS)
	@$(MAKE) clean -C ./libft

fclean: clean
	rm -f $(NAME)
	@$(MAKE) fclean -C ./libft

re: fclean all

.PHONY: clean fclean re all