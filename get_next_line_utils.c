/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arkadiusz <arkadiusz@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 17:22:27 by aoperacz          #+#    #+#             */
/*   Updated: 2025/02/28 19:39:19 by arkadiusz        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	unsigned long	i;
	unsigned long	j;
	char			*res;

	i = 0;
	res = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1));
	if (res == NULL)
		return (NULL);
	while (s1 != NULL && s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 != NULL && s2[j])
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)(s + i));
	return ((void *)0);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*str;
	unsigned long	i;

	i = 0;
	str = s;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	tsize;
	void	*arr;

	tsize = nmemb * size;
	arr = malloc(tsize);
	if (arr == NULL)
		return (NULL);
	ft_bzero(arr, tsize);
	return (arr);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i] != 0)
	{
		i++;
	}
	return (i);
}
