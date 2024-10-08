/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_graphics.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saylital <saylital@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 10:05:59 by saylital          #+#    #+#             */
/*   Updated: 2024/09/05 18:32:59 by saylital         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	load_textures(t_game_data *game)
{
	game->texture = ft_calloc(1, sizeof(t_texture));
	if (!game->texture)
		perror_map(game->map_2d, NULL, "calloc fail load_textures");
	game->texture->floor = mlx_load_png("./images/floor.png");
	game->texture->wall = mlx_load_png("./images/wall.png");
	game->texture->exit = mlx_load_png("./images/exit.png");
	game->texture->player = mlx_load_png("./images/player.png");
	game->texture->collect = mlx_load_png("./images/collectible.png");
	if (!game->texture->floor || !game->texture->wall || !game->texture->exit
		|| !game->texture->player || !game->texture->collect)
	{
		ft_putstr_fd("Error\nmlx_load_png failed\n", 2);
		rmv_textures(game);
	}
}

static void	load_images(t_game_data *game, mlx_t *mlx)
{
	game->image = ft_calloc(1, sizeof(t_image));
	if (!game->image)
	{
		ft_putstr_fd("Error\ncalloc fail load_images\n", 2);
		rmv_textures(game);
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
	free(game->texture);
	if (!game->image->floor || !game->image->wall || !game->image->exit
		|| !game->image->player || !game->image->collect)
	{
		ft_putstr_fd("Error\nmlx_texture_to_image failed\n", 2);
		rmv_images(game);
	}
}

void	put_img_win(mlx_image_t *img, t_game_data *game, int y, int x)
{
	if (!mlx_resize_image(img, SIZE, SIZE))
	{
		ft_putstr_fd("Error\nmlx_resize_image failed\n", 2);
		rmv_images(game);
	}
	if (mlx_image_to_window(game->mlx, img, x * SIZE, y * SIZE) == -1)
	{
		ft_putstr_fd("Error\nmlx_image_to_window failed\n", 2);
		rmv_images(game);
	}
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
			put_img_win(game->image->floor, game, y, x);
			if (map[y][x] == '1')
				put_img_win(game->image->wall, game, y, x);
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

void	game_graphics(t_game_data *game)
{
	char	**map;

	map = game->map_2d;
	load_textures(game);
	load_images(game, game->mlx);
	draw_images(game, map);
}
