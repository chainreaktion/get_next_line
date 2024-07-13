/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschmitz <jschmitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 19:58:09 by jschmitz          #+#    #+#             */
/*   Updated: 2024/07/13 22:27:42 by jschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	read_line(char ***buffer_set, int fd)
{
	int		read_output;
	char	buf_string[BUFFER_SIZE];
	size_t	i;
	size_t	j;

	i = 0;
	while (ft_strchr(buf_string, '\n') == 0)
	{
		read_output = read (fd, buf_string, BUFFER_SIZE);
		if (read_output < 0)
			return (-1);
		if (read_output == 0)
			return (0);
		*buffer_set[i] = ft_strdup(buf_string);
		i++;
	}
	while (*buffer_set[i][j] != '\n')
	{
		*buffer_set[i][j] = buf_string[j];
		j++;
	}
	return (read_output);
}

char	*get_next_line(int fd)
{
	char	*line;
	size_t	array_siz;
	size_t	line_length;
	char	**buffer_set;
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
		free_array (buffer_set, array_siz);
		return (NULL);
	}
	//nbyte is the buffer size and it's given with the function call..?
	//read returns -1 if there is an error
	while (i <= array_siz)
	{
		buffers_to_line(&buffer_set, &line);
		i++;
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
