/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arkadiusz <arkadiusz@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 17:22:33 by aoperacz          #+#    #+#             */
/*   Updated: 2025/02/19 23:12:00 by arkadiusz        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char *buffer, char *buff)
{
	char	*temp;

	temp = ft_strjoin(buff, buffer);
	return (temp);
}

char	*read_data(int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	ssize_t	bytes_read;
	char	*buff;
	char	*temp;

	buff = NULL;
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read == -1)
		return (free(buff), NULL);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		temp = ft_free(buffer, buff);
		if (!temp)
			return (free(buff), NULL);
		free (buff);
		buff = temp;
		if (ft_strchr(buff, '\n'))
			break ;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free (buff), NULL);
	}
	return (buff);
}

char	*find_line(char *data)
{
	int		i;
	char	*line;

	if (!data || *data == '\0')
		return (NULL);
	i = 0;
	while (data[i] != '\n' && data[i])
		i++;
	if (data[i] == '\n')
		i++;
	line = ft_calloc(i + 1, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (data[i] != '\n' && data[i])
	{
		line[i] = data[i];
		i++;
	}
	if (data[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*find_remaining_data(char *data)
{
	ssize_t	i;
	ssize_t	j;
	char	*leftover;

	if (!data)
		return (NULL);
	j = 0;
	i = 0;
	while (data[i] != '\n' && data[i] != '\0')
		i++;
	if (data[i] == '\0')
		return (NULL);
	i++;
	leftover = (char *)malloc((ft_strlen(data) - i + 1) * sizeof(char));
	if (!leftover)
		return (NULL);
	while (data[i + j])
	{
		leftover[j] = data[i + j];
		j++;
	}
	leftover[j] = '\0';
	return (leftover);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*data;
	static char	*saved_data;
	char		*temp;

	data = read_data(fd);
	if (!data && !saved_data)
		return (NULL);
	temp = ft_strjoin(saved_data, data);
	free(saved_data);
	free(data);
	if (!temp)
		return (NULL);
	saved_data = temp;
	if (!saved_data || *saved_data == '\0')
	{
		free(saved_data);
		saved_data = NULL;
		return (NULL);
	}
	line = find_line(saved_data);
	temp = find_remaining_data(saved_data);
	free(saved_data);
	saved_data = temp;
	return (line);
}
// char	*get_next_line(int fd)
// {
// 	char		*line;
// 	char		*data;
// 	static char	*saved_data;

// 	data = read_data(fd);
// 	if (!data)
// 	{
// 		if (ft_strlen(saved_data) > 0)
// 			free(saved_data);
// 		return (NULL);
// 	}
// 	line = ft_strjoin(saved_data, data);
// 	free(data);
// 	saved_data = find_remaining_data(line);
// 	line = find_line(line);
// 	return (line);
// }
