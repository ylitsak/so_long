/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keypress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saylital <saylital@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:22:16 by saylital          #+#    #+#             */
/*   Updated: 2024/09/01 19:55:52 by saylital         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_up(t_game_data *game)
{
	int	y;
	int	x;
	
	y = game->player_pos_y - 1;
	x = game->player_pos_x;
	if (game->map_2d[y][x] == '1')
		return ;
	if (game->map_2d[y][x] == 'C')
	{
		game->map_2d[y][x] = '0';
		game->collectibles--;
	}
	if (game->map_2d[y][x] == 'E' && game->collectibles == 0)
		mlx_close_window(game->mlx);
	put_img_win(game->image->floor,game, game->player_pos_y, game->player_pos_x);
	game->player_pos_y = y;
	game->player_pos_x = x;
	put_img_win(game->image->player,game, game->player_pos_y, game->player_pos_x);
	game->move_count++;
	ft_printf("moves %d\n", game->move_count);
}

static void	move_down(t_game_data *game)
{
	int	y;
	int	x;
	
	y = game->player_pos_y + 1;
	x = game->player_pos_x;
	if (game->map_2d[y][x] == '1')
		return ;
	if (game->map_2d[y][x] == 'C')
	{
		game->map_2d[y][x] = '0';
		game->collectibles--;
	}
	if (game->map_2d[y][x] == 'E' && game->collectibles == 0)
		mlx_close_window(game->mlx);
	put_img_win(game->image->floor,game, game->player_pos_y, game->player_pos_x);
	game->player_pos_y = y;
	game->player_pos_x = x;
	put_img_win(game->image->player,game, game->player_pos_y, game->player_pos_x);
	game->move_count++;
	ft_printf("moves %d\n", game->move_count);
}

static void	move_left(t_game_data *game)
{
	int	y;
	int	x;
	
	y = game->player_pos_y;
	x = game->player_pos_x - 1;
	if (game->map_2d[y][x] == '1')
		return ;
	if (game->map_2d[y][x] == 'C')
	{
		game->map_2d[y][x] = '0';
		game->collectibles--;
	}
	if (game->map_2d[y][x] == 'E' && game->collectibles == 0)
		mlx_close_window(game->mlx);
	put_img_win(game->image->floor,game, game->player_pos_y, game->player_pos_x);
	game->player_pos_y = y;
	game->player_pos_x = x;
	put_img_win(game->image->player,game, game->player_pos_y, game->player_pos_x);
	game->move_count++;
	ft_printf("moves %d\n", game->move_count);
}

static void	move_right(t_game_data *game)
{
	int	y;
	int	x;
	
	y = game->player_pos_y;
	x = game->player_pos_x + 1;
	if (game->map_2d[y][x] == '1')
		return ;
	if (game->map_2d[y][x] == 'C')
	{
		game->map_2d[y][x] = '0';
		game->collectibles--;
	}
	if (game->map_2d[y][x] == 'E' && game->collectibles == 0)
		mlx_close_window(game->mlx);
	put_img_win(game->image->floor,game, game->player_pos_y, game->player_pos_x);
	game->player_pos_y = y;
	game->player_pos_x = x;
	put_img_win(game->image->player,game, game->player_pos_y, game->player_pos_x);
	game->move_count++;
	ft_printf("moves %d\n", game->move_count);
}
void	handle_keypress(mlx_key_data_t keydata, void *param)
{
	t_game_data	*game;

	game = param;
	if (keydata.key == MLX_KEY_ESCAPE &&  keydata.action == MLX_PRESS)
		mlx_close_window(game->mlx);
	if (keydata.key == MLX_KEY_UP &&  keydata.action == MLX_PRESS)
		move_up(game);
	if (keydata.key == MLX_KEY_DOWN &&  keydata.action == MLX_PRESS)
		move_down(game);
	if (keydata.key == MLX_KEY_LEFT &&  keydata.action == MLX_PRESS)
		move_left(game);
	if (keydata.key == MLX_KEY_RIGHT &&  keydata.action == MLX_PRESS)
		move_right(game);
}