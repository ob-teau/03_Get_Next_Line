/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoinus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 15:29:00 by acoinus           #+#    #+#             */
/*   Updated: 2021/05/11 15:29:04 by acoinus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		return_line(char **rest, char **line, int x)
{
	int		i;

	i = 0;
	if (x < 0)
		return (-1);
	if (*rest && ((i = check_n(*rest)) >= 0))
		return (split(rest, line, i));
	else if (*rest)
	{
		*line = *rest;
		*rest = 0;
		return (0);
	}
	*line = ft_strdup("");
	free(*rest);
	return (0);
}

int		split(char **rest, char **line, int i)
{
	char	*s;
	int		len;

	len = ft_strlen(*rest + i + 1);
	(*rest)[i] = '\0';
	*line = ft_strdup(*rest);
	if (len == 0)
	{
		free(*rest);
		*rest = 0;
		return (1);
	}
	s = ft_strdup(*rest + i + 1);
	free(*rest);
	*rest = s;
	return (1);
}

int		check_n(char *s)
{
	int		i;

	i = 0;
	while (s && s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int		get_next_line(int fd, char **line)
{
	char			buff[BUFFER_SIZE + 1];
	static char		*rest[1024];
	int				x;
	int				i;

	i = 0;
	x = 0;
	if ((fd < 0) || (line == 0) || (BUFFER_SIZE <= 0))
		return (-1);
	while ((x = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[x] = '\0';
		rest[fd] = ft_join(rest[fd], buff);
		if ((i = check_n(rest[fd])) >= 0)
			return (split(&rest[fd], line, i));
	}
	return (return_line(&rest[fd], line, x));
}
