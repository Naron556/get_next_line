/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arkadiusz <arkadiusz@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 17:21:26 by aoperacz          #+#    #+#             */
/*   Updated: 2025/03/07 18:29:10 by arkadiusz        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# elif BUFFER_SIZE > 1000000
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 1000000
# endif
# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_strjoin(const char *left, const char *right);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *sauce, int num_char);
int		ft_strlen(const char *str);

#endif