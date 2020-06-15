/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifaveur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 12:51:16 by ifaveur           #+#    #+#             */
/*   Updated: 2020/06/12 18:58:58 by ifaveur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char			*ft_strdup(const char *source)
{
	int		i;
	char	*dest;
	int		x;

	i = ft_strlen((char *)source);
	dest = malloc((i + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	x = 0;
	while (source[x])
	{
		dest[x] = source[x];
		x++;
	}
	dest[x] = '\0';
	return (dest);
}

static char		*ft_cutsave(char *str, char **line)
{
	int		i;
	char	*temp;

	i = ft_strlenl(str);
	*line = ft_substr(str, 0, i);
	temp = ft_substr(str, i + 1, ft_strlen(&str[i]));
	free(str);
	return (temp);
}

static char		*ft_freestatic(char *str, int i)
{
	if (i == 0)
	{
		free(str);
		str = NULL;
	}
	return (str);
}

static int		ft_readfd(char **save, char *buffer, int i)
{
	char		*str;

	buffer[i] = '\0';
	str = *save;
	*save = ft_strjoin(str ? str : "", buffer);
	if (str)
		free(str);
	if (!*save)
		return (0);
	return (1);
}

int				get_next_line(int fd, char **line)
{
	char		buffer[BUFFER_SIZE + 1];
	int			i;
	static char	*save[256];

	if (fd < 0 || BUFFER_SIZE < 1 || !line || read(fd, buffer, 0) == -1)
		return (-1);
	while (!ft_strchr(save[fd], '\n') &&
			(i = read(fd, buffer, BUFFER_SIZE)) > 0)
		if (ft_readfd(&save[fd], buffer, i) == 0)
			return (-1);
	i = 0;
	if (ft_strchr(save[fd], '\n'))
		i = 1;
	if (save[fd])
	{
		save[fd] = ft_cutsave(save[fd], line);
		if (save[fd] == NULL)
			return (-1);
	}
	else if (!(*line = ft_strdup("")))
		return (-1);
	save[fd] = ft_freestatic(save[fd], i);
	return (*line ? i : -1);
}
