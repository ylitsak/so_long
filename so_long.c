/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saylital <saylital@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 10:24:38 by saylital          #+#    #+#             */
/*   Updated: 2024/09/01 19:19:41 by saylital         ###   ########.fr       */
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
	game->move_count = 0;
}

int	main(int argc, char *argv[])
{
	static t_game_data	game;
	// mlx_t		*mlx;

	//mlx_set_setting(MLX_STRETCH_IMAGE, 1);
	init_struct(&game);
	check_map(argc, argv, &game);
	game.mlx = mlx_init(game.map_rows*SIZE, game.map_cols*SIZE, "so_long", true);
	if (!game.mlx)
		perror_map(game.map_2d, NULL, "mlx init failure");
	game_graphics(&game, game.mlx);
	mlx_key_hook(game.mlx, &handle_keypress, &game);
	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);
	free_all(game.map_2d);
	return (0);
}

