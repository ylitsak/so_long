/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_graphics.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saylital <saylital@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 10:05:59 by saylital          #+#    #+#             */
/*   Updated: 2024/08/28 15:47:30 by saylital         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	load_textures(t_game_data *game)
{
	game->texture = ft_calloc(1, sizeof(t_texture));
	if(!game->texture)
		perror_map(game->map_2d, NULL, "calloc fail textures");
	game->texture->floor = mlx_load_png("./images/floor.png");
	game->texture->wall = mlx_load_png("./images/wall.png");
	game->texture->exit = mlx_load_png("./images/exit.png");
	game->texture->player = mlx_load_png("./images/player.png");
	game->texture->collect = mlx_load_png("./images/collectible.png");

}
static void	load_images(t_game_data *game, mlx_t *mlx)
{
	game->image = ft_calloc(1, sizeof(t_image));
	if(!game->image)
	{
		mlx_delete_texture(game->texture);
		perror_map(game->map_2d, NULL, "calloc fail images")
	}
	game->image->wall = mlx_texture_to_image(mlx, game->texture->wall);
	game->image->floor = mlx_texture_to_image(mlx, game->texture->floor);
	game->image->exit = mlx_texture_to_image(mlx, game->texture->exit);
	game->image->player = mlx_texture_to_image(mlx, game->texture->player);
	game->image->collect = mlx_texture_to_image(mlx, game->texture->collect);
}

void	game_graphics(t_game_data *game, mlx_t *mlx)
{
	char	**map;

	map = game->map_2d;
	load_textures(game);
	load_images(game, mlx);
}