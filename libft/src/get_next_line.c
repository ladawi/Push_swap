/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladawi <ladawi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 14:05:00 by ladawi            #+#    #+#             */
/*   Updated: 2022/01/11 16:35:58 by ladawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"
#include <limits.h>

int	read_file(int fd, char **rest, int buff)
{
	char	*str;

	if (ft_gnlstrchr(*rest, '\n') != -1)
		return (1);
	str = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!(str))
		return (-1);
	*str = '\0';
	while (ft_gnlstrchr(str, '\n') == -1 && buff > 0)
	{
		buff = read(fd, str, BUFFER_SIZE);
		if (buff >= 0)
		{
			str[buff] = '\0';
			if (!(*rest))
				*rest = ft_gnlsubstr(str, 0, buff);
			else
				*rest = ft_gnlstrjoin(*rest, str);
		}
	}
	free(str);
	if (buff > 0)
		return (1);
	return (buff);
}

int	stock_rest(int fd, char **rest, char **line)
{
	char	*to_free;
	int		error;
	int		len;

	if (!(line))
		return (-1);
	error = read_file(fd, rest, 1);
	if (error < 0)
		return (-1);
	len = ft_gnlstrchr(*rest, '\n');
	if (len == -1)
		len = ft_gnlstrlen(*rest);
	*line = ft_gnlsubstr(*rest, 0, len);
	if (!(*line))
		return (-1);
	to_free = *rest;
	*rest = ft_gnlsubstr(*rest, len + 1, ft_gnlstrlen(*rest) + len + 1);
	if (to_free)
	{
		free(to_free);
		to_free = NULL;
	}
	return (error);
}

int	get_next_line(int fd, char **line)
{
	static char	*rest[OPEN_MAX];
	int			error;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (-1);
	error = stock_rest(fd, &rest[fd], line);
	if (rest[fd] && (error == -1 || error == 0))
	{
		free(rest[fd]);
		rest[fd] = NULL;
	}
	return (error);
}
