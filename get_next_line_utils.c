/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 00:32:24 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/06/14 01:52:03 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	size;

	size = 0;
	while (s[size] != '\0')
		size++;
	return (size);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*string;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	string = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!string)
		return (NULL);
	i = 0;
	while (s1 != NULL && s1[i] != '\0')
	{
		string[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 != NULL && s2[j] != '\0')
	{
		string[i + j] = s2[j];
		j++;
	}
	string[i + j] = '\0';
	return (string);
}

int	ft_strnchr(const char *s)
{
	int				i;
	unsigned char	*temp;

	i = 0;
	temp = (unsigned char *)s;
	while (temp[i] != '\0')
	{
		if (temp[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strdup(const char *s)
{
	char	*dup;

	dup = (char *)malloc(ft_strlen(s) + 1);
	if (!dup)
		return (NULL);
	ft_strlcpy(dup, s, ft_strlen(s) + 1);
	return (dup);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	pos;

	if (!dst || !src)
		return (0);
	pos = 0;
	if (size > 0)
	{
		while (pos < size - 1 && src[pos])
		{
			dst[pos] = src[pos];
			pos++;
		}
		dst[pos] = '\0';
	}
	pos = 0;
	while (src[pos] != '\0')
	{
		pos++;
	}
	return (pos);
}
