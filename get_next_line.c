/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arkadiusz <arkadiusz@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 17:22:33 by aoperacz          #+#    #+#             */
/*   Updated: 2025/03/07 18:29:13 by arkadiusz        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_chunk(int fd, char **data)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*temp;
	int		bytes_read;

	temp = NULL;
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	buffer[bytes_read] = '\0';
	if (bytes_read == -1)
	{
		free(*data);
		return (bytes_read);
	}
	while (bytes_read > 0)
	{
		temp = *data;
		*data = ft_strjoin(temp, buffer);
		free(temp);
		if (ft_strchr(*data, '\n'))
			break ;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		buffer[bytes_read] = '\0';
		if (bytes_read == -1)
			return (free(*data), bytes_read);
	}
	return (bytes_read);
}

char	*return_line_and_leftover(char *data, char **leftover)
{
	char	*line;
	int		itr;

	line = ft_strjoin(*leftover, data);
	free(data);
	free(*leftover);
	data = line;
	if (data == NULL)
		return (NULL);
	itr = 0;
	while (data[itr] != '\0' && data[itr] != '\n')
		itr++;
	if (data[itr] == '\n')
		itr++;
	line = ft_strdup(data, itr);
	*leftover = ft_strdup(data + itr, ft_strlen(data + itr));
	if (**leftover == '\0')
	{
		free(*leftover);
		*leftover = NULL;
	}
	free(data);
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*data;
	char		*temp;
	static char	*leftover;
	int			bytes_read;

	data = NULL;
	temp = ft_strdup(leftover, ft_strlen(leftover));
	bytes_read = get_chunk(fd, &data);
	if (bytes_read == -1 && leftover != NULL)
	{
		free(leftover);
		free(temp);
		leftover = NULL;
		return (NULL);
	}
	line = return_line_and_leftover(data, &temp);
	if (leftover != NULL)
		free(leftover);
	leftover = temp;
	return (line);
}
