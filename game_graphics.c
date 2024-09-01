/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_graphics.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saylital <saylital@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 10:05:59 by saylital          #+#    #+#             */
/*   Updated: 2024/09/01 18:51:45 by saylital         ###   ########.fr       */
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
		mlx_delete_texture(game->texture->floor);
		mlx_delete_texture(game->texture->wall);
		mlx_delete_texture(game->texture->exit);
		mlx_delete_texture(game->texture->player);
		mlx_delete_texture(game->texture->collect);
		perror_map(game->map_2d, NULL, "calloc fail images");
	}
	game->image->wall = mlx_texture_to_image(mlx, game->texture->wall);
	game->image->floor = mlx_texture_to_image(mlx, game->texture->floor);
	game->image->exit = mlx_texture_to_image(mlx, game->texture->exit);
	game->image->player = mlx_texture_to_image(mlx, game->texture->player);
	game->image->collect = mlx_texture_to_image(mlx, game->texture->collect);
	mlx_delete_texture(game->texture->floor);
	mlx_delete_texture(game->texture->wall);
	mlx_delete_texture(game->texture->exit);
	mlx_delete_texture(game->texture->player);
	mlx_delete_texture(game->texture->collect);
}
int	put_img_win(mlx_image_t *img, t_game_data *game, int y, int x)
{
	if (!mlx_resize_image(img, SIZE, SIZE))
	{
		mlx_delete_image(game->mlx, img);
		perror_map(game->map_2d, NULL, "image to window failed");
	}
	if (mlx_image_to_window(game->mlx, img, x * SIZE, y * SIZE) == -1)
	{
		mlx_delete_image(game->mlx, img);
		perror_map(game->map_2d, NULL, "image to window failed");
	}
	return (1);
}

static void	draw_images(t_game_data *game, char **map)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if(map[y][x] == '1')
				put_img_win(game->image->wall, game, y, x);
			else if (map[y][x] == '0')
				put_img_win(game->image->floor, game, y, x);
			else if (map[y][x] == 'E')
				put_img_win(game->image->exit, game, y, x);
			else if (map[y][x] == 'P')
				put_img_win(game->image->player, game, y, x);
			else if (map[y][x] == 'C')
				put_img_win(game->image->collect, game, y, x);
			x++;			
		}
		y++;
	}
}

void	game_graphics(t_game_data *game, mlx_t *mlx)
{
	char	**map;

	map = game->map_2d;
	load_textures(game);
	load_images(game, mlx);
	draw_images(game, map);
}