/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saylital <saylital@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 11:02:39 by saylital          #+#    #+#             */
/*   Updated: 2024/08/15 13:53:51 by saylital         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_exists(char *input)
{
	int	fd;

	fd = open(input, O_RDONLY);
	if ((fd) == -1)
	{
		perror("Error\nOpening map");
		exit(EXIT_FAILURE);
	}
	return (fd);
}

static int	ends_with_ber(const char *input, const char *ber)
{
	int			whole_string;
	int			ber_len;
	const char	*check_ber;
	
	whole_string = ft_strlen(input);
	ber_len = ft_strlen(ber);
	check_ber = input + whole_string - ber_len;
	if (ft_strncmp(check_ber, ber, ber_len) == 0)
		return (0);
	return (1);
}

static void	check_map_args(int argc, char *argv[])
{
	if (argc != 2)
	{
		ft_printf("Error\nIncorrect amount of arguments, expected %d, got %d\n", 1, argc -1);
		exit(EXIT_FAILURE);
	}
	if (ends_with_ber(argv[1], ".ber") != 0)
	{
		ft_printf("Error\nWrong map extension: %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
}

void	check_valid_map(int argc, char *argv[], t_game_data *game)
{
	check_map_args(argc, argv);
	game->map_size = size_of_map(argv[1]);
	ft_printf("map size: %d\n", game->map_size);
	game->map_1d = store_map(argv[1], game->map_size);
	ft_printf("%s\n", game->map_1d);
	free(game->map_1d);
	
	return ;
}
