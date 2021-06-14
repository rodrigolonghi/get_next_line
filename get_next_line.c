/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 00:32:11 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/06/14 03:00:25 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_result(char *save, char **line, ssize_t size)
{
	if (size == -1)
		return (-1);
	if (!save)
	{
		*line = ft_strdup("");
		return (0);
	}
	*line = ft_strdup(save);
	return (1);
}

static char	*ft_remove_nl(char *str)
{
	char	*dup;
	int		size;
	int		pos;
	int		x;

	pos = 0;
	size = 0;
	while (str[pos])
	{
		if (str[pos] != '\n')
			size++;
		pos++;
	}
	dup = (char *)malloc(size + 1);
	pos = 0;
	x = 0;
	while (str[pos])
	{
		if (str[pos] != '\n')
			dup[pos] = str[pos + x];
		else
			x++;
		pos++;
	}
	return (dup);
}

int	get_next_line(int fd, char **line)
{
	static char	*save;
	char		*buf;
	ssize_t		size;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	buf = malloc(BUFFER_SIZE + 1);
	size = read(fd, buf, BUFFER_SIZE);
	while (size > 0)
	{
		buf[size] = '\0';
		if (ft_strnchr(buf) != -1)
		{
			buf = ft_remove_nl(buf);
			size = -1;
		}
		if (!save)
			save = ft_strdup(buf);
		else
			save = ft_strdup(ft_strjoin(save, buf));
		if (size > 0)
			size = read(fd, buf, BUFFER_SIZE);
	}
	free(buf);
	return (ft_result(save, line, size));
}
