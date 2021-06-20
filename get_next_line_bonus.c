/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 20:52:06 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/06/19 22:24:44 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	ft_remove_nl(char **save, char **line)
{
	char	*temp;
	int		size;

	size = 0;
	while ((*save)[size] != '\0' && (*save)[size] != '\n')
		size++;
	if ((*save)[size] == '\0')
	{
		*line = ft_strdup(*save);
		if (*save != NULL)
		{
			free(*save);
			*save = NULL;
		}
		return (0);
	}
	*line = ft_substr(*save, 0, size);
	temp = ft_strdup((*save) + size + 1);
	free(*save);
	*save = temp;
	return (1);
}

static int	ft_result(char **save, char **line, ssize_t size)
{
	if (size == -1 || BUFFER_SIZE <= 0 || !line)
		return (-1);
	if (*save == NULL && size == 0)
	{
		*line = ft_strdup("");
		return (0);
	}
	return (ft_remove_nl(save, line));
}

int	get_next_line(int fd, char **line)
{
	static char	*save[1024];
	char		*buf;
	char		*temp;
	ssize_t		size;

	buf = malloc(BUFFER_SIZE + 1);
	size = read(fd, buf, BUFFER_SIZE);
	while (size > 0)
	{
		buf[size] = '\0';
		if (!save[fd])
			save[fd] = ft_strdup(buf);
		else
		{
			temp = ft_strjoin(save[fd], buf);
			free(save[fd]);
			save[fd] = temp;
		}
		if (ft_strchr(save[fd]))
			break ;
		size = read(fd, buf, BUFFER_SIZE);
	}
	free(buf);
	return (ft_result(&(save[fd]), line, size));
}
