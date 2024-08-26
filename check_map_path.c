/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saylital <saylital@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 13:52:01 by saylital          #+#    #+#             */
/*   Updated: 2024/08/26 10:14:45 by saylital         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**copy_map(t_game_data *game)
{
	int		i;
	char	**map_copy;

	i = 0;
	map_copy = malloc((game->map_rows) * sizeof(char *));
	if (!map_copy)
		perror_map(game->map_2d, "Malloc failed");
	while (i < game->map_rows && game->map_2d[i] != NULL)
	{
		map_copy[i] = ft_strdup(game->map_2d[i]);
		if (map_copy[i] == NULL)
		{
			while (i > 0)
			{
				free(map_copy[i]);
				i--;
			}
			free(map_copy);
			perror_map(game->map_2d, "Malloc failed");
		}
		i++;
	}
	map_copy[i] = NULL;
	print_map(map_copy);
	return (map_copy);
}

static void	dfs(t_game_data *game, t_path_check *path_check, int x, int y)
{
	if (x < 0 || y < 0 || y >= game->map_rows || x >= game->map_cols)
		return ;
	if (path_check->map_copy[x][y] == '1')
		return ;
	if (path_check->map_copy[x][y] == 'C')
		path_check->collectibles_found += 1;
	if (path_check->map_copy[x][y] == 'E')
		path_check->exit_found += 1;
	path_check->map_copy[x][y] = '1';
	dfs(game, path_check, x - 1, y);
	dfs(game, path_check, x + 1, y);
	dfs(game, path_check, x, y - 1);
	dfs(game, path_check, x, y + 1);
	return ;
}

static int	valid_path(t_game_data *game)
{
	game->path_check.map_copy = copy_map(game);
	game->path_check.exit_found = 0;
	game->path_check.collectibles_found = 0;
	dfs(game, &game->path_check, game->player_pos_x, game->player_pos_y);
	print_map(game->path_check.map_copy);
	if (game->path_check.collectibles_found == game->collectibles
		&& game->path_check.exit_found == 1)
	{
		free_all(game->path_check.map_copy);
		return (1);
	}
	free_all(game->path_check.map_copy);
	return (0);
}

void	validate_map_path(t_game_data *game)
{
	if (valid_path(game))
		return ;
	else
		ft_printf("Error\nFailed to find valid path");
}
