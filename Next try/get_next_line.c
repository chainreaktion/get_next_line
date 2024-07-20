/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschmitz <jschmitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 19:58:09 by jschmitz          #+#    #+#             */
/*   Updated: 2024/07/20 19:01:15 by jschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	read_line(int fd, char **line, char **buf_cpy)
{
	int		read_output;
	char 	*buffer;

	read_output = 1;
	while (read_output != 0)
	{
		buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
		if (buffer == NULL)
			return (-1);
		read_output = read (fd, buffer, BUFFER_SIZE);
		if (read_output < 0)
			return (free(buffer), -1);
		if (ft_strdup(buffer, buf_cpy) == -1)
			return (free(buffer), -1);
		if (ft_strchr(buf_cpy, '\n') != 0 || ft_strchr(buf_cpy, '\0') != 0)
			break ;
		if (ft_strjoin(*line, *buf_cpy, &line) == -1)
			return (free(buffer), -1);
	}
	return (free(buffer), read_output);
}

int	last_buffer(char *last_buf, char **tmp)
{
	int		i;
	int		j;

	i = 0;
	j= 0;
	while (last_buf[i] != '\n' && last_buf[i] != '\0')
		i++;
	tmp = (char *)malloc(sizeof(char) * i + 1);
	if (tmp == NULL)
		return (free (last_buf), -1);
	while (j <= i)
	{
		tmp[j] = last_buf[j];
		j++;
	}
	if (tmp[j - 1] != '\0')
		tmp[j]= '\0';
	return (0);
}

int	start_nextline(char *buf_cpy, char **line_start)
{
	int	i;
	int	j;

	i = 0;
	while (buf_cpy[i] && buf_cpy[i] != '\n')
		i++;
	j = i + 1;
	line_start = (char *)malloc(sizeof(char) * (ft_strlen(buf_cpy) + 1));
	if (line_start == NULL)
		return (-1);
	i = 0;
	while (buf_cpy[j])
		(*line_start)[i++] = buf_cpy[j++];
	(*line_start)[i] = '\0';
	return (0);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buf_cpy;
	static char	*line_start;
	char		*last_buf;
	int			output_signal;

if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
{
	return (free_all, NULL);
}
	line = "";
	if (line_start == 0)
		line_start = "";
	else if (ft_strchr(line_start, '\n') != 0 || ft_strchr(line_start, '\0') != 0)
	{
		output_signal = border_case(line_start, &line, &buf_cpy);
		if (output_signal == -1)
			return (free(line_start), free(buf_cpy), NULL)
		line = ft_strjoin(line, last_buf);
		if (ft_strchr(buf_cpy, '\n') != 0)
			line_start = start_nextline(buf_cpy, line_start);
		free (last_buf);
		free (buf_cpy);
		return (line);
	}
	output_signal = ft_strjoin(line, line_start, &line);
	if (output_signal == -1)
		return (free_all, NULL);
	output_signal = read_line(fd, &line, &buf_cpy);
	if (output_signal == -1)
		return (free_all, NULL);
	if (output_signal == 0)
		return (free(buf_cpy), free(line_start), line);
	if (output_signal < BUFFER_SIZE)
	{
		if (ft_strjoin(line, buf_cpy, &line) == -1)
			return (free(buf_cpy), free(line_start), NULL);
		return (free(buf_cpy), free(line_start), line);
	}
	if (ft_strchr(buf_cpy, '\n') != 0 || ft_strchr(buf_cpy, '\0') != 0)
	{
		last_buf = last_buffer(buf_cpy);
		if (last_buf == NULL)
			return (NULL);
		line = ft_strjoin(line, last_buf);
		if (ft_strchr(buf_cpy, '\n') != 0)
			start_nextline(buf_cpy, &line_start);
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

