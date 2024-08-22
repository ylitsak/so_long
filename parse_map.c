/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saylital <saylital@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 18:48:04 by saylital          #+#    #+#             */
/*   Updated: 2024/08/22 16:27:36 by saylital         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	perror_element(char **map, int player, int collect, int m_exit)
{
	if (player != 1)
		ft_printf("Error\nInvalid player count: %d\n", player);
	if (collect < 1)
		ft_printf("Error\nInvalid collectibles: %d\n", collect);
	if (m_exit != 1)
		ft_printf("Error\nInvalid exit count: %d\n", m_exit);
	free_all(map);
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
				perror_map(map, "Invalid characters in map\n");
			if (map[cols][rows] == 'P')
				game->player += 1;
			else if (map[cols][rows] == 'C')
				game->collectibles += 1;
			else if (map[cols][rows] == 'E')
				game->map_exit += 1;
			rows++;
		}
		cols++;
	}
	if (game->player != 1 || game->collectibles < 1 || game->map_exit != 1)
		perror_element(map, game->player, game->collectibles, game->map_exit);
}

static void	wall_check(char **map, int rows, int cols)
{
	while (map[0][rows])
	{
		if (map[0][rows] != '1')
			perror_map(map, "Map do not pass wall check\n");
		rows++;
	}
	while (map[cols])
		cols++;
	rows = 0;
	while (map[cols - 1][rows])
	{
		if (map[cols - 1][rows] != '1')
			perror_map(map, "Map do not pass wall check\n");
		rows++;
	}
	rows = ft_strlen(map[0]);
	cols = 0;
	while (map[cols])
	{
		if (map[cols][0] != '1' || map[cols][rows - 1] != '1')
			perror_map(map, "Map do not pass wall check\n");
		cols++;
	}
}

static void	is_rectangular(char **map, int rows, int cols)
{
	int	first_row;

	first_row = ft_strlen(map[0]);
	while (map[cols])
		cols++;
	if (cols < 2)
		perror_map(map, "Map is not rectangular\n");
	cols = 0;
	while (map[cols])
	{
		rows = ft_strlen(map[cols]);
		if (rows != first_row)
		{
			perror_map(map, "Map is not rectangular\n");
		}
		cols++;
	}
}

void	validate_map(t_game_data *game)
{
	int		rows;
	int		cols;
	char	**map;

	map = game->map_2d;
	rows = 0;
	cols = 0;
	is_rectangular(map, rows, cols);
	wall_check(map, rows, cols);
	valid_map_element(game, map, rows, cols);
}
