/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saylital <saylital@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 10:24:38 by saylital          #+#    #+#             */
/*   Updated: 2024/09/05 19:27:35 by saylital         ###   ########.fr       */
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

static void	free_game_data(t_game_data *game)
{
	if (game->image)
	{
		if (game->image->wall)
			mlx_delete_image(game->mlx, game->image->wall);
		if (game->image->collect)
			mlx_delete_image(game->mlx, game->image->collect);
		if (game->image->player)
			mlx_delete_image(game->mlx, game->image->player);
		if (game->image->exit)
			mlx_delete_image(game->mlx, game->image->exit);
		if (game->image->floor)
			mlx_delete_image(game->mlx, game->image->floor);
		free(game->image);
	}
	free_all(game->map_2d);
	mlx_terminate(game->mlx);
}

int	main(int argc, char *argv[])
{
	t_game_data	game;

	init_struct(&game);
	check_map(argc, argv, &game);
	game.mlx = mlx_init(game.map_rows * SIZE, game.map_cols * SIZE,
			"so_long", true);
	if (!game.mlx)
		perror_map(game.map_2d, NULL, "mlx init failure");
	game_graphics(&game);
	mlx_key_hook(game.mlx, &handle_keypress, &game);
	mlx_loop(game.mlx);
	free_game_data(&game);
	return (0);
}
