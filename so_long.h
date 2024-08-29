/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saylital <saylital@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 11:02:40 by saylital          #+#    #+#             */
/*   Updated: 2024/08/29 12:32:46 by saylital         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "libft/libft.h"
# include "MLX42/include/MLX42/MLX42.h"
# include <stdio.h>
# include <fcntl.h>
# define SIZE 150

typedef struct s_texture
{
	mlx_texture_t	*floor;
	mlx_texture_t	*wall;
	mlx_texture_t	*exit;
	mlx_texture_t	*player;
	mlx_texture_t	*collect;
}	t_texture;

typedef struct s_image
{
	mlx_image_t	*floor;
	mlx_image_t	*wall;
	mlx_image_t	*exit;
	mlx_image_t	*player;
	mlx_image_t	*collect;
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
	mlx_t		*mlx;
	t_texture	*texture;
	t_image		*image;
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
void	game_graphics(t_game_data *game, mlx_t *mlx);
//error_messages.c
void	perror_malloc(void);
void	perror_read(int fd);
void	perror_map(char **map, char *map_1, char *message);
//utility_functions.c
void	free_all(char **free_data);
void	print_map(char **map);

#endif
