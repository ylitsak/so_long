/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saylital <saylital@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 12:55:03 by saylital          #+#    #+#             */
/*   Updated: 2024/08/15 13:20:23 by saylital         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	perror_malloc(void)
{
	perror("Error\nMalloc failed");
	exit(EXIT_FAILURE);
}

void	perror_read(int fd)
{
	perror("Error\nRead failed");
	close(fd);
	exit(EXIT_FAILURE);
}
