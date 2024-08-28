/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saylital <saylital@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 10:24:38 by saylital          #+#    #+#             */
/*   Updated: 2024/08/28 15:50:35 by saylital         ###   ########.fr       */
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
	mlx_t		mlx;
	mlx_t		texture;

	init_struct(&game);
	check_map(argc, argv, &game);
	if (!(mlx = mlx_init(game->cols *SIZE, game->rows *SIZE, "so_long", true)))
		perror_map(game.map_2d, NULL, "mlx init failure");
	game_graphics(&game, &mlx);

	// mlx_texture_t* texture = mlx_load_png("./images/wall.png");
	// if (!texture)
    //     error();
	// mlx_image_t* img = mlx_texture_to_image(mlx, texture);
	// if (!img)
    //     error();

	// if (mlx_image_to_window(mlx, img, 0, 0) < 0)
    //     error();

	// mlx_loop(mlx);
	// mlx_delete_image(mlx, img);
	// mlx_delete_texture(texture);
	// mlx_terminate(mlx);
	free_all(game.map_2d);
	return (0);
}

