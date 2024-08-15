/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saylital <saylital@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 18:48:04 by saylital          #+#    #+#             */
/*   Updated: 2024/08/15 22:08:42 by saylital         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// static void	valid_map_elements(char **map)
// {

// }

static void	wall_check(char **map, int rows, int cols)
{
	while (map[0][rows])
	{
		if (map[0][rows] != '1')
			perror_wall(map);
		rows++;
	}
	while (map[cols])
		cols++;
	rows = 0;
	while (map[cols - 1][rows])
	{
		if (map[cols - 1][rows] != '1')
			perror_wall(map);
		rows++;
	}
	rows = ft_strlen(map[0]);
	cols = 0;
	while (map[cols])
	{
		if (map[cols][0] != '1' || map[cols][rows - 1] != '1')
			perror_wall(map);
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
		perror_rectangular(map);
	cols = 0;
	while (map[cols])
	{
		rows = ft_strlen(map[cols]);
		if (rows != first_row)
		{
			perror_rectangular(map);
		}
		cols++;
	}
}

void	validate_map(char **map)
{
	int	rows;
	int	cols;

	rows = 0;
	cols = 0;
	is_rectangular(map, rows, cols);
	wall_check(map, rows, cols);
	// valid_map_elements(map);
}
