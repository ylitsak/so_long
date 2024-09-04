/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saylital <saylital@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 11:02:39 by saylital          #+#    #+#             */
/*   Updated: 2024/09/04 10:02:13 by saylital         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_extra_newlines(char *map_1d)
{
	int	i;

	i = 0;
	if (map_1d[0] == '\n')
	{
		ft_putstr_fd("Error\nMap contains extra newlines\n", 2);
		free(map_1d);
		exit(EXIT_FAILURE);
	}
	while (map_1d[i])
	{
		if (map_1d[i] == '\n' && map_1d[i + 1] == '\n')
		{
			ft_putstr_fd("Error\nMap contains extra newlines\n", 2);
			free(map_1d);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	if (map_1d[i - 1] == '\n')
	{
		ft_putstr_fd("Error\nMap contains extra newlines\n", 2);
		free(map_1d);
		exit(EXIT_FAILURE);
	}
}

static int	ends_with_ber(const char *input, const char *ber)
{
	int			whole_string;
	int			ber_len;
	const char	*check_ber;

	whole_string = ft_strlen(input);
	ber_len = ft_strlen(ber);
	check_ber = input + whole_string - ber_len;
	if ((ft_strncmp(check_ber, ber, ber_len) == 0) && ft_strlen(input) > 4)
		return (0);
	return (1);
}

static void	check_map_args(int argc, char *argv[])
{
	if (argc != 2)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("Incorrect arguments, expected 1", 2);
		exit(EXIT_FAILURE);
	}
	if (ends_with_ber(argv[1], ".ber") != 0)
	{
		ft_putstr_fd("Error\nWrong map extension\n", 2);
		exit(EXIT_FAILURE);
	}
}

void	check_map(int argc, char *argv[], t_game_data *game)
{
	check_map_args(argc, argv);
	game->map_size_buf = size_of_map(argv[1]);
	game->map_1d = store_map(argv[1], game->map_size_buf);
	check_extra_newlines(game->map_1d);
	game->map_2d = ft_split(game->map_1d, '\n');
	if (!game->map_2d)
	{
		free(game->map_1d);
		ft_putstr_fd("Error\nft_split fail\n", 2);
		exit(EXIT_FAILURE);
	}
	parse_map(game);
	validate_map_path(game);
	return ;
}
