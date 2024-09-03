/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saylital <saylital@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 13:52:01 by saylital          #+#    #+#             */
/*   Updated: 2024/09/03 20:25:29 by saylital         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	dfs(t_game_data *game, char **map, int x, int y)
{
	if (map[y][x] == '1' || map[y][x] == 'X')
		return ;
	if (map[y][x] == 'C')
		game->collectibles_found += 1;
	if (map[y][x] == 'E')
		game->exit_found += 1;
	map[y][x] = 'X';
	dfs(game, map, x + 1, y);
	dfs(game, map, x - 1, y);
	dfs(game, map, x, y + 1);
	dfs(game, map, x, y - 1);
	return ;
}

static int	valid_path(t_game_data *game)
{
	char	**map_copy;

	map_copy = ft_split(game->map_1d, '\n');
	free(game->map_1d);
	game->exit_found = 0;
	game->collectibles_found = 0;
	dfs(game, map_copy, game->player_pos_x, game->player_pos_y);
	if (game->collectibles_found == game->collectibles
		&& game->exit_found == 1)
	{
		free_all(map_copy);
		return (1);
	}
	free_all(map_copy);
	return (0);
}

void	validate_map_path(t_game_data *game)
{
	if (valid_path(game))
		return ;
	else
		perror_map(game->map_2d, NULL, "No valid path found\n");
}
