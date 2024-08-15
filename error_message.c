/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saylital <saylital@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 12:55:03 by saylital          #+#    #+#             */
/*   Updated: 2024/08/15 22:07:15 by saylital         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	perror_malloc(void)
{
	ft_printf("Error\nMalloc failed\n");
	exit(EXIT_FAILURE);
}

void	perror_read(int fd)
{
	perror("Error\nRead failed");
	close(fd);
	exit(EXIT_FAILURE);
}

void	perror_rectangular(char **map)
{
	ft_printf("Error\nMap is not rectangular\n");
	free_all(map);
	exit(EXIT_FAILURE);
}

void	perror_wall(char **map)
{
	ft_printf("Error\nMap do not pass wall check\n");
	free_all(map);
	exit(EXIT_FAILURE);
}
