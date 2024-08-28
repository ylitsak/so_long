/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saylital <saylital@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 11:02:40 by saylital          #+#    #+#             */
/*   Updated: 2024/08/28 15:36:11 by saylital         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "libft/libft.h"
# include "MLX42/include/MLX42/MLX42.h"
# include <stdio.h>
# include <fcntl.h>
# define WIDTH 1024
# define HEIGHT 1024
# define SIZE 35

typedef struct s_texture
{
	mlx_texture	*floor;
	mlx_texture	*wall;
	mlx_texture	*exit;
	mlx_texture	*player;
	mlx_texture	*collect;
}	t_texture;

typedef struct s_image
{
	mlx_image	*floor;
	mlx_image	*wall;
	mlx_image	*exit;
	mlx_image 	*player;
	mlx_image	*collect;
}	t_image;

typedef struct s_game_data
{
	char		*map_1d;
	char		**map_2d;
	int			map_size_buf;
	int			map_rows;
	int			map_cols;
	int			player_pos_x;
	int			player_pos_y;
	int			player;
	int			collectibles;
	int			map_exit;
	int			exit_found;
	int			collectibles_found;
	texture_t	*texture;
	image_t		*image
}	t_game_data;

//check_map.c
void	check_map(int argc, char *argv[], t_game_data *game);
//map_to_memory.c
int		size_of_map(char *filename);
char	*store_map(char *map, int size);
//parse_map.c
void	parse_map(t_game_data *game);
//validate_map_path
void	validate_map_path(t_game_data *game);
//game_graphics.c
void	game_graphics(t_game_data *game, mlx_t, *mlx);
//error_messages.c
void	perror_malloc(void);
void	perror_read(int fd);
void	perror_map(char **map, char *map_1, char *message);
//utility_functions.c
void	free_all(char **free_data);
void	print_map(char **map);

#endif
