/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saylital <saylital@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 11:02:40 by saylital          #+#    #+#             */
/*   Updated: 2024/08/15 22:35:27 by saylital         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h" // can i use this? or include stdio for perror and fcntl for open myself

typedef struct s_game_data
{
	char	*map_1d;
	char	**map_2d;
	int		map_size;
	int		x;
	int		y;
	int		player;
	int		collectibles;
}	t_game_data;

//check_map.c
void	check_valid_map(int argc, char *argv[], t_game_data *game);
//map_to_memory.c
int		size_of_map(char *filename);
char	*store_map(char *map, int size);
//parse_map.c
void	validate_map(char **map);
//error_messages.c
void	perror_malloc(void);
void	perror_read(int fd);
void	perror_rectangular(char **map);
void	perror_wall(char **map);
//utility_functions.c
void	free_all(char **free_data);
void	print_map(char **map);

#endif
