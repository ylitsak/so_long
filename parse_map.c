/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saylital <saylital@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 18:48:04 by saylital          #+#    #+#             */
/*   Updated: 2024/09/04 10:09:46 by saylital         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	perror_element(t_game_data *game)
{
	if (game->player != 1)
		ft_putstr_fd("Error\nInvalid player count\n", 2);
	if (game->collectibles < 1)
		ft_putstr_fd("Error\nInvalid amount of collectibles\n", 2);
	if (game->map_exit != 1)
		ft_putstr_fd("Error\nInvalid exit count\n", 2);
	free(game->map_1d);
	free_all(game->map_2d);
	exit(EXIT_FAILURE);
}

static void	valid_map_element(t_game_data *game, char **map, int rows, int cols)
{
	while (map[cols])
	{
		rows = 0;
		while (map[cols][rows])
		{
			if (!ft_strchr("01PEC", map[cols][rows]))
				perror_map(map, game->map_1d, "Invalid characters in map");
			if (map[cols][rows] == 'P')
			{
				game->player += 1;
				game->player_pos_y = cols;
				game->player_pos_x = rows;
			}
			else if (map[cols][rows] == 'C')
				game->collectibles += 1;
			else if (map[cols][rows] == 'E')
				game->map_exit += 1;
			rows++;
		}
		cols++;
	}
	if (game->player != 1 || game->collectibles < 1 || game->map_exit != 1)
		perror_element(game);
}

static void	wall_check(char **map, t_game_data *game, int rows, int cols)
{
	while (map[0][rows])
	{
		if (map[0][rows] != '1')
			perror_map(map, game->map_1d, "Map do not pass wall check");
		rows++;
	}
	while (map[cols])
		cols++;
	rows = 0;
	while (map[cols - 1][rows])
	{
		if (map[cols - 1][rows] != '1')
			perror_map(map, game->map_1d, "Map do not pass wall check");
		rows++;
	}
	rows = ft_strlen(map[0]);
	cols = 0;
	while (map[cols])
	{
		if (map[cols][0] != '1' || map[cols][rows - 1] != '1')
			perror_map(map, game->map_1d, "Map do not pass wall check");
		cols++;
	}
}

static void	is_rectangular(t_game_data *game, char **map, int rows, int cols)
{
	int	first_row;

	first_row = ft_strlen(map[0]);
	while (map[cols])
		cols++;
	if (cols < 2 || first_row < 2)
		perror_map(map, game->map_1d, "Map is not rectangular");
	cols = 0;
	while (map[cols])
	{
		rows = ft_strlen(map[cols]);
		if (rows != first_row)
		{
			perror_map(map, game->map_1d, "Map is not rectangular");
		}
		cols++;
	}
	game->map_rows = first_row;
	game->map_cols = cols;
}

void	parse_map(t_game_data *game)
{
	int		rows;
	int		cols;
	char	**map;

	map = game->map_2d;
	rows = 0;
	cols = 0;
	is_rectangular(game, map, rows, cols);
	wall_check(map, game, rows, cols);
	valid_map_element(game, map, rows, cols);
}
