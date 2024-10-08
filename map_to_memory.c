/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_memory.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saylital <saylital@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 17:58:08 by saylital          #+#    #+#             */
/*   Updated: 2024/09/04 09:55:16 by saylital         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	map_exists(char *input)
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

char	*store_map(char *map, int size)
{
	int		fd;
	int		bytes_read;
	char	*buffer;

	fd = map_exists(map);
	buffer = malloc((size + 1) * sizeof(char));
	if (!buffer)
	{
		ft_putstr_fd("Error\nMalloc failed\n", 2);
		exit(EXIT_FAILURE);
	}
	bytes_read = read(fd, buffer, size);
	if (bytes_read == -1)
	{
		free(buffer);
		perror_read(fd);
	}
	else if (bytes_read != size)
	{
		free(buffer);
		perror_read(fd);
	}
	close(fd);
	buffer[size] = '\0';
	return (buffer);
}
