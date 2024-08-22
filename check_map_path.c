/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saylital <saylital@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 13:52:01 by saylital          #+#    #+#             */
/*   Updated: 2024/08/22 14:56:20 by saylital         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	player_position(t_game_data *game)
{
	char	**map;
	int		cols;
	int		rows;

	map = game->map_2d;
	cols = 0;
	rows = 0;
	while (map[cols])
	{
		rows = 0;
		while (map[cols][rows])
		{
			if (map[cols][rows] == 'P')
			{
				game->player_pos_y = cols;
				game->player_pos_x = rows;
				return ;
			}
			rows++;
		}
		cols++;
	}
}

void	validate_map_path(t_game_data *game)
{
	player_position(game);
	printf("PLAYER POSITION Y:%d, X:%d\n", game->player_pos_y, game->player_pos_x);
}