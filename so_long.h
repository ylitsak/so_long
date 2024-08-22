/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saylital <saylital@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 11:02:40 by saylital          #+#    #+#             */
/*   Updated: 2024/08/22 14:07:25 by saylital         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "libft/libft.h"
# include "MLX42/include/MLX42/MLX42.h"
# include <stdio.h>
# include <fcntl.h>

typedef struct s_game_data
{
	char	*map_1d;
	char	**map_2d;
	int		map_size;
	int		x;
	int		y;
	int		player_pos_x;
	int		player_pos_y;
	int		player;
	int		collectibles;
	int		exit;
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
void	perror_rectangular(char **map);
void	perror_wall(char **map);
//utility_functions.c
void	free_all(char **free_data);
void	print_map(char **map);

#endif
