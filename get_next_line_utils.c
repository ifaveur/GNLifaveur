/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifaveur <ifaveur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 11:42:47 by ifaveur           #+#    #+#             */
/*   Updated: 2020/06/12 18:58:37 by ifaveur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int		ft_strlenl(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

char	*ft_strchr(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != c)
		i++;
	if (str[i] == c)
		return ((char *)&str[i]);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	int		size;
	char	*str;

	if (s1 && s2)
	{
		size = ft_strlen((char *)s1);
		size += ft_strlen((char *)s2);
		str = malloc((size + 1) * sizeof(char));
		if (!str)
			return (NULL);
		j = -1;
		while (s1 && s1[++j])
			str[j] = s1[j];
		i = -1;
		while (s2 && s2[++i])
			str[j + i] = s2[i];
		str[j + i] = '\0';
		return (str);
	}
	return (NULL);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t		i;
	size_t		j;
	char		*str;

	if (!s)
		return (NULL);
	i = 0;
	if (ft_strlen((char *)s) < (int)start)
		return (ft_strdup(""));
	j = ft_strlen((char *)&s[start]);
	if (j < len)
		len = j;
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
