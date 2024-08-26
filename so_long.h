/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saylital <saylital@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 11:02:40 by saylital          #+#    #+#             */
/*   Updated: 2024/08/26 10:17:52 by saylital         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "libft/libft.h"
# include "MLX42/include/MLX42/MLX42.h"
# include <stdio.h>
# include <fcntl.h>

typedef struct s_path_check
{
	int		exit_found;
	int		collectibles_found;
	char	**map_copy;
}	t_path_check;

typedef struct s_game_data
{
	char			*map_1d;
	char			**map_2d;
	int				map_size_buf;
	int				map_rows;
	int				map_cols;
	int				player_pos_x;
	int				player_pos_y;
	int				player;
	int				collectibles;
	int				map_exit;
	t_path_check	path_check;
}	t_game_data;

//check_map.c
void	check_valid_map(int argc, char *argv[], t_game_data *game);
//map_to_memory.c
int		size_of_map(char *filename);
char	*store_map(char *map, int size);
//parse_map.c
void	validate_map(t_game_data *game);
//check_map_path
void	validate_map_path(t_game_data *game);
//error_messages.c
void	perror_malloc(void);
void	perror_read(int fd);
void	perror_map(char **map, char *message);
//utility_functions.c
void	free_all(char **free_data);
void	print_map(char **map);

#endif
