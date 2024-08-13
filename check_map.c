/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saylital <saylital@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 11:02:39 by saylital          #+#    #+#             */
/*   Updated: 2024/08/13 12:25:38 by saylital         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	map_exists(char *input)
{
	int	fd_map;

	fd_map = open(input, O_RDONLY);
	if ((fd_map) == -1)
	{
		perror("Error opening map");
		close(fd_map);
		exit(EXIT_FAILURE);
	}
	close(fd_map);
	return ;
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
		ft_printf("Error: incorrect amount of arguments, expected %d, got %d\n", 1, argc -1);
		exit(EXIT_FAILURE);
	}
	if (ends_with_ber(argv[1], ".ber") != 0)
	{
		ft_printf("Error: wrong map extension: %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	map_exists(argv[1]);
}

void	check_valid_map(int argc, char *argv[])
{
	check_map_args(argc, argv);
}