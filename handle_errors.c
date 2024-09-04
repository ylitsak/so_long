/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saylital <saylital@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 12:55:03 by saylital          #+#    #+#             */
/*   Updated: 2024/09/04 09:00:42 by saylital         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	perror_read(int fd)
{
	perror("Error\nRead failed");
	close(fd);
	exit(EXIT_FAILURE);
}

void	perror_map(char **map, char *map_1, char *message)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(message, 2);
	if (map_1 != NULL)
		free(map_1);
	free_all(map);
	exit(EXIT_FAILURE);
}

void	free_all(char **free_data)
{
	int	i;

	i = 0;
	while (free_data[i])
	{
		free(free_data[i]);
		i++;
	}
	free(free_data);
}

void	rmv_textures(t_game_data *game)
{
	if (game->texture->wall)
		mlx_delete_texture(game->texture->wall);
	if (game->texture->collect)
		mlx_delete_texture(game->texture->collect);
	if (game->texture->player)
		mlx_delete_texture(game->texture->player);
	if (game->texture->exit)
		mlx_delete_texture(game->texture->exit);
	if (game->texture->floor)
		mlx_delete_texture(game->texture->floor);
	free(game->texture);
	free_all(game->map_2d);
	mlx_terminate(game->mlx);
	exit(EXIT_FAILURE);
}

void	rmv_images(t_game_data *game)
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
	free_all(game->map_2d);
	mlx_terminate(game->mlx);
	exit(EXIT_FAILURE);
}
