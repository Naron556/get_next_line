/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arkadiusz <arkadiusz@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 17:22:27 by aoperacz          #+#    #+#             */
/*   Updated: 2025/03/07 18:29:17 by arkadiusz        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *sauce, int num_char)
{
	int		itr_th_sauce;
	char	*duplicate;

	if (!sauce)
		return (NULL);
	duplicate = malloc((num_char + 1) * sizeof(char));
	if (duplicate == NULL)
		return (NULL);
	itr_th_sauce = 0;
	while (sauce[itr_th_sauce] != '\0' && itr_th_sauce != num_char)
	{
		duplicate[itr_th_sauce] = sauce[itr_th_sauce];
		itr_th_sauce++;
	}
	duplicate[itr_th_sauce] = '\0';
	return (duplicate);
}

int	ft_strlen(const char *str)
{
	int	str_len;

	if (str == NULL)
		return (0);
	str_len = 0;
	while (str[str_len] != '\0')
		str_len++;
	return (str_len);
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

char	*ft_strjoin(const char *left, const char *right)
{
	int		itr_th_left;
	int		itr_th_right;
	char	*joined;

	if (left == NULL && right == NULL)
		return (NULL);
	joined = malloc((ft_strlen(left) + ft_strlen(right) + 1) * sizeof(char));
	if (joined == NULL)
		return (NULL);
	itr_th_left = 0;
	while (left != NULL && left[itr_th_left] != '\0')
	{
		joined[itr_th_left] = left[itr_th_left];
		itr_th_left++;
	}
	itr_th_right = 0;
	while (right != NULL && right[itr_th_right] != '\0')
	{
		joined[itr_th_left + itr_th_right] = right[itr_th_right];
		itr_th_right++;
	}
	joined[itr_th_left + itr_th_right] = '\0';
	return (joined);
}
