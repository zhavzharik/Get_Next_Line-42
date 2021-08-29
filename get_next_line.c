/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 12:15:25 by abridger          #+#    #+#             */
/*   Updated: 2021/06/06 16:22:48 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*check_rest(char *rest, char **line)
{
	char	*n_point;

	n_point = NULL;
	if (rest)
	{
		n_point = ft_strchr(rest, '\n');
		if (n_point)
		{
			*n_point = '\0';
			*line = ft_strdup(rest);
			ft_strcpy(rest, ++n_point);
		}
		else
			*line = ft_strdup(rest);
	}
	else
	{
		*line = ft_strdup("");
		if (!*line)
			return (NULL);
	}
	return (n_point);
}

int	check_lesen(int lesen, char **buf, char **line)
{
	if (lesen < 0)
	{
		free(*buf);
		free(*line);
		*line = NULL;
		return (-1);
	}
	return (1);
}

int	get_rest_and_line(char **n_point, char **buf, char **rest, char **line)
{
	*n_point = ft_strchr(*buf, '\n');
	if (*n_point)
	{
		**n_point = '\0';
		(*n_point)++;
		free(*rest);
		*rest = ft_strdup(*n_point);
		if (*rest == NULL)
		{
			free(*buf);
			return (-1);
		}
	}
	*line = ft_strjoin(*line, *buf);
	if (!*line)
	{
		free(*rest);
		free(*buf);
		return (-1);
	}
	return (1);
}

int	get_return(char **buf, int lesen, char **rest, char **line)
{
	free(*buf);
	*buf = NULL;
	if (lesen == 0)
	{
		free(*rest);
		*rest = NULL;
		return (0);
	}
	if ((lesen || ft_strlen(*rest) || ft_strlen(*line) != 0))
		return (1);
	return (0);
}

int	get_next_line(int fd, char **line)
{
	char		*buf;
	int			lesen;
	char		*n_point;
	static char	*rest;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (-1);
	lesen = 1;
	n_point = check_rest(rest, line);
	while (!n_point && lesen != 0)
	{
		lesen = read(fd, buf, BUFFER_SIZE);
		if (check_lesen(lesen, &buf, line) == -1)
			return (-1);
		buf[lesen] = '\0';
		if (get_rest_and_line(&n_point, &buf, &rest, line) == -1)
			return (-1);
	}
	return (get_return(&buf, lesen, &rest, line));
}
