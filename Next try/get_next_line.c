/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschmitz <jschmitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 19:58:09 by jschmitz          #+#    #+#             */
/*   Updated: 2024/07/19 22:48:57 by jschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(int fd, char **line, char *buf_cpy)
{
	int		read_output;
	char	buffer[BUFFER_SIZE + 1];

	read_output = 1;
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

char*	last_buffer(char *last_buf)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j= 0;
	while (last_buf[i] != '\n' && last_buf[i] != '\0')
		i++;
	tmp = (char *)malloc(sizeof(char) * i + 1);
	if (tmp == NULL)
		return (free (last_buf), NULL);
	while (j <= i)
	{
		tmp[j] = last_buf[j];
		j++;
	}
	if (tmp[j - 1] != '\0')
		tmp[j]= '\0';
	return (tmp);
}

char*	start_nextline(char *buf_cpy)
{
	int	i;
	int	j;
	char *line_start;

	i = 0;
	while (buf_cpy[i] && buf_cpy[i] != '\n')
		i++;
	j = i + 1;
	line_start = (char *)malloc(sizeof(char) * (ft_strlen(buf_cpy) + 1));
	if (line_start == NULL)
		return (free (buf_cpy), NULL);
	i = 0;
	while (buf_cpy[j])
		line_start[i++] = buf_cpy[j++];
	line_start[i] = '\0';
	return (line_start);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buf_cpy;
	static char	*line_start;
	char		*last_buf;

if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
{
	free (line_start);
	free (line);
	free(buf_cpy);
	return (NULL);
}
	line = "";
	if (line_start == 0)
		line_start = "";
	if (ft_strchr(line_start, '\n') != 0 || ft_strchr(line_start, '\0') != 0)
	{
		buf_cpy = strdup(line_start);
		last_buf = last_buffer(buf_cpy);
		if (last_buf == NULL)
			return (NULL);
		line = ft_strjoin(line, last_buf);
		if (ft_strchr(buf_cpy, '\n') != 0)
			line_start = start_nextline(buf_cpy, line_start);
		free (last_buf);
		free (buf_cpy);
		return (line);
	}
	line = ft_strjoin(line, line_start);
	buf_cpy = read_line(fd, &line, buf_cpy);
	if (ft_strchr(buf_cpy, '\n') != 0 || ft_strchr(buf_cpy, '\0') != 0)
	{
		last_buf = last_buffer(buf_cpy);
		if (last_buf == NULL)
			return (NULL);
		line = ft_strjoin(line, last_buf);
		if (ft_strchr(buf_cpy, '\n') != 0)
			line_start = start_nextline(buf_cpy, line_start);
	}
	free (last_buf);
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
	line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
	close (fd);
	free (line);
	return (0);
}

