/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschmitz <jschmitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 17:13:00 by jschmitz          #+#    #+#             */
/*   Updated: 2024/07/13 19:15:26 by jschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s) + i);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)(s) + i);
	return (0);
}
size_t	array_size(char **buffer)
{
	size_t	i;

	i = 0;
	while (buffer[i] != NULL)
		i++;
	return (i);
}
size_t	ft_strcat(char *dst, const char *src)
{
	size_t	len_d;
	size_t	len_s;
	size_t	i;

	len_d = ft_strlen(dst);
	len_s = ft_strlen(src);
	i = 0;
	while (src[i])
	{
		dst[len_d + i] = src[i];
		i++;
	}
	dst[len_d + i] = '\0';
	return (len_d + len_s);
}

void	buffers_to_line(char ***buffers, char **line)
{
	size_t	i;
	char	*res;
	size_t 	buff_iter;

	buff_iter = array_size(*buffers) / BUFFER_SIZE;
	i = 0;
	while (i < buff_iter)
	{
		ft_strcat(*buffers[i], *line);
		i++;
	}
}

void	free_array(char **s, int i)
{
	int	c;

	c = 0;
	while (c < i)
	{
		free(s[c]);
		c++;
	}
	free(s);
}
char	*ft_strdup(const char *s)
{
	int		i;
	char	*cpy;

	cpy = malloc (sizeof(char) * (ft_strlen(s) + 1));
	if (cpy == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		cpy[i] = s[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
