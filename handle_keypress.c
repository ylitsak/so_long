/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keypress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saylital <saylital@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:22:16 by saylital          #+#    #+#             */
/*   Updated: 2024/09/01 21:57:00 by saylital         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	draw_previous_tile(t_game_data *game, int current_y, int current_x)
{
	if (game->map_2d[current_y][current_x] == 'E')
	{
		put_img_win(game->image->floor, game, current_y, current_x);
		put_img_win(game->image->exit, game, current_y, current_x);
	}
	else
	{
		put_img_win(game->image->floor, game, current_y, current_x);
	}
}

static void	draw_new_tile(t_game_data *game, int new_y, int new_x)
{
	put_img_win(game->image->floor, game, new_y, new_x);
	if (game->map_2d[new_y][new_x] == 'E')
	{
		put_img_win(game->image->exit, game, new_y, new_x);
	}
	put_img_win(game->image->player, game, new_y, new_x);
}

static void	move_player(t_game_data *game, int new_y, int new_x)
{
	int	current_y;
	int	current_x;

	current_y = game->player_pos_y;
	current_x = game->player_pos_x;
	if (game->map_2d[new_y][new_x] == '1')
		return ;
	if (game->map_2d[new_y][new_x] == 'C')
	{
		game->map_2d[new_y][new_x] = '0';
		game->collectibles--;
	}
	if (game->map_2d[new_y][new_x] == 'E' && game->collectibles == 0)
	{
		mlx_close_window(game->mlx);
		return ;
	}
	draw_previous_tile(game, current_y, current_x);
	game->player_pos_y = new_y;
	game->player_pos_x = new_x;
	draw_new_tile(game, new_y, new_x);
	game->move_count++;
	ft_printf("moves %d\n", game->move_count);
}

void	handle_keypress(mlx_key_data_t keydata, void *param)
{
	t_game_data	*game;

	game = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(game->mlx);
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
		move_player(game, game->player_pos_y - 1, game->player_pos_x);
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
		move_player(game, game->player_pos_y + 1, game->player_pos_x);
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		move_player(game, game->player_pos_y, game->player_pos_x - 1);
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		move_player(game, game->player_pos_y, game->player_pos_x + 1);
}
