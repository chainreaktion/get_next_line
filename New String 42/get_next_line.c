/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschmitz <jschmitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 19:58:09 by jschmitz          #+#    #+#             */
/*   Updated: 2024/07/17 15:02:38 by jschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(int fd, char **line, char *buf_cpy)
{
	int		read_output;
	char	buffer[BUFFER_SIZE];
	size_t	i;

	i = 0;
	read_output = 1;
	if

	while (read_output != 0)
	{
		read_output = read (fd, buffer, BUFFER_SIZE);
		if (read_output < 0)
			return (-1);
		if (read_output == 0)
			return (NULL);
		buf_cpy = ft_strdup(buffer);
		if (ft_strchr(buf_cpy, '\n') == 0 || ft_strchr(buf_cpy, '\n') == 0)
			return (buf_cpy);
		line = ft_strjoin(line, buf_cpy);
		i++;
	}

	return (buf_cpy);
}

char	*get_next_line(int fd)
{
	char	*line;
	size_t	array_siz;
	size_t	line_length;
	char	*buf_cpy;
	size_t	i;

	if (read_line(&buffer_set, fd) < 0)
	{
		return (NULL);
	}
	array_siz = array_size(buffer_set);
	line_length = (array_siz - 1) * BUFFER_SIZE + ft_strlen(buffer_set[array_siz]);
	line = (char *)malloc(sizeof(char) * line_length + 1);
	if (line == NULL)
	{
		free(buf_cpy)
		return (NULL);
	}


	return (line);
}

int	main (void)
{
	char	*line;
	int		fd;

	fd = open("testfile.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		return (1);
	}
	line = get_next_line(fd);
	printf("%s", line);
	close (fd);
	return (0);
}
