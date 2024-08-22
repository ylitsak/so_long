/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saylital <saylital@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 12:55:03 by saylital          #+#    #+#             */
/*   Updated: 2024/08/22 15:58:25 by saylital         ###   ########.fr       */
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

void	perror_map(char **map, char *message)
{
	ft_printf("Error\n%s", message);
	free_all(map);
	exit(EXIT_FAILURE);
}
