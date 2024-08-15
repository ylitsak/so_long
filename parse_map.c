/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saylital <saylital@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 18:48:04 by saylital          #+#    #+#             */
/*   Updated: 2024/08/15 20:24:32 by saylital         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// static void	valid_map_elements(char **map)
// {

// }

// static void	wall_check(char **map)
// {

// }

static void	is_rectangular(char **map)
{
	int	rows;
	int	cols;
	int	first_row;

	cols = 0;
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
	is_rectangular(map);
	// wall_check(map);
	// valid_map_elements(map);
}