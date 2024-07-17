/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschmitz <jschmitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 19:58:09 by jschmitz          #+#    #+#             */
/*   Updated: 2024/07/18 00:08:04 by jschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(int fd, char **line, char *buf_cpy)
{
	int		read_output;
	char	buffer[BUFFER_SIZE + 1];

	read_output = 1;
	printf("read_line function start");
	while (read_output != 0)
	{
		read_output = read (fd, buffer, BUFFER_SIZE);
		if (read_output < 0)
			return (NULL);
			//error message missing
		if (read_output == 0)
			break ;
		buf_cpy = ft_strdup(buffer);
		if (ft_strchr(buf_cpy, '\n') != 0 || ft_strchr(buf_cpy, '\n') != 0)
			return (buf_cpy);
		*line = ft_strjoin(*line, buf_cpy);
	}
	return (buf_cpy);
}

int	last_buffer(char **line, char **next_line_start, char *last_buf)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j= 0;
	while (last_buf[i] != '\n' && last_buf[i] != '\0')
		i++;
	tmp = (char *)malloc(sizeof(char) * i + 1);
	if (line_end == NULL)
		return (NULL);
	while (j <= i)
	{
		line_end[j] = last_buf[j];
		j++;
	}
	if (line_end[j - 1] != '\0')
		line_end[j]= '\0';
	return (line_end);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buf_cpy;
	static char	*line_start;

	if (line_start = 0)
		line_start = ft_strdup("");
	line = ft_strjoin(line, line_start);
	buf_cpy = read_line(fd, &line, buf_cpy);
	if (ft_strchr(buf_cpy, '\n') != 0 || ft_strchr(buf_cpy, '\0') != 0)
		last_buffer(&line, buf_cpy);
	free (buf_cpy);
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
	free (line);
	return (0);
}

