/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoinus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 15:13:13 by acoinus           #+#    #+#             */
/*   Updated: 2021/05/11 15:27:06 by acoinus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

int		get_next_line(int fd, char **line);
char	*ft_join(char *s1, char *s2);
int		ft_strlen(char *s);
int		ft_strlcpy(char *dst, char *src, int dstsize);
char	*ft_strdup(char *s);
int		ft_strlcat(char *dst, char *src, int dstsize);
int		check_n(char *s);
int		split(char **rest, char **line, int x);
int		return_line(char **rest, char **line, int x);

#endif
