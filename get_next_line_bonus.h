/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifaveur <ifaveur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 13:45:06 by ifaveur           #+#    #+#             */
/*   Updated: 2020/06/08 13:45:27 by ifaveur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

int			get_next_line(int fd, char **line);
char		*ft_strchr(char *str, char c);
char		*ft_strjoin(char *s1, char *s2);
int			ft_strlen(char *str);
char		*ft_strdup(const char *source);
int			ft_strlenl(char *str);
char		*ft_substr(char *s, unsigned int start, size_t len);

#endif
