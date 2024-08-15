/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_memory.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saylital <saylital@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 17:58:08 by saylital          #+#    #+#             */
/*   Updated: 2024/08/15 13:06:29 by saylital         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	size_of_map(char *filename)
{
	int		fd;
	int		size;
	int		bytes_read;
	char	buffer;

	size = 0;
	fd = map_exists(filename);
	bytes_read = read(fd, &buffer, 1);
	while (bytes_read > 0)
	{
		size += bytes_read;
		bytes_read = read(fd, &buffer, 1);
	}
	if (bytes_read == -1)
		perror_read(fd);
	close(fd);
	return (size);
}

char	*store_map(char *map, t_game_data *game)
{
	int		fd;
	int		bytes_read;
	int		total_read;
	char	*buffer;

	fd = map_exists(map);
	total_read = 0;
	buffer = malloc((game->map_size + 1) * sizeof(char));
	if (!buffer)
		perror_malloc();
	bytes_read = read(fd, buffer + total_read, game->map_size - total_read);
	while (bytes_read > 0)
	{
		total_read += bytes_read;
		bytes_read = read(fd, buffer + total_read, game->map_size - total_read);
	}
	if (bytes_read == -1)
	{
		free(buffer);
		perror_read(fd);
	}
	close(fd);
	buffer[game->map_size] = '\0';
	return (buffer);
}
