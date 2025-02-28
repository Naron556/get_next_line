/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arkadiusz <arkadiusz@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 21:46:56 by arkadiusz         #+#    #+#             */
/*   Updated: 2025/02/19 22:25:58 by arkadiusz        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("nice.txt", O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("Line: %s", line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (0);
}
