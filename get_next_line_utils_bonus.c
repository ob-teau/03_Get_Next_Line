/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoinus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 15:29:36 by acoinus           #+#    #+#             */
/*   Updated: 2021/05/11 15:29:41 by acoinus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		ft_strlcat(char *dst, char *src, int dstsize)
{
	int		i;
	int		dst_len;
	int		src_len;

	i = 0;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	while ((src[i] != '\0') && ((dst_len + 1 + i) < dstsize))
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	if (dstsize < dst_len)
		return (dstsize + src_len);
	return (dst_len + src_len);
}

int		ft_strlen(char *s)
{
	int		i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

int		ft_strlcpy(char *dst, char *src, int size)
{
	int		src_len;
	int		i;

	i = 0;
	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	while ((src[i] != '\0') && (i < (size - 1)))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}

char	*ft_strdup(char *s)
{
	char	*new;
	int		i;

	i = 0;
	if (!(new = malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (0);
	while (s[i])
	{
		new[i] = s[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_join(char *s1, char *s2)
{
	char	*new;
	int		s1_len;

	s1_len = ft_strlen(s1);
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	if (!(new = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	ft_strlcpy(new, s1, (s1_len + 1));
	free(s1);
	ft_strlcat((new + s1_len), s2, (ft_strlen(s2) + 1));
	return (new);
}
