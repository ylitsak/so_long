/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saylital <saylital@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 10:24:38 by saylital          #+#    #+#             */
/*   Updated: 2024/08/26 14:31:57 by saylital         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_struct(t_game_data *game)
{
	game->map_1d = NULL;
	game->map_2d = NULL;
	game->map_size_buf = 0;
	game->map_rows = 0;
	game->map_cols = 0;
	game->player_pos_x = 0;
	game->player_pos_y = 0;
	game->player = 0;
	game->collectibles = 0;
	game->map_exit = 0;
	game->collectibles_found = 0;
	game->exit_found = 0;
}

int	main(int argc, char *argv[])
{
	t_game_data	game;

	init_struct(&game);
	check_map(argc, argv, &game);
	free_all(game.map_2d);
	return (0);
}
