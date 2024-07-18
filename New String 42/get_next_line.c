/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschmitz <jschmitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 19:58:09 by jschmitz          #+#    #+#             */
/*   Updated: 2024/07/18 21:09:49 by jschmitz         ###   ########.fr       */
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
		return (NULL);
	while (j <= i)
	{
		tmp[j] = last_buf[j];
		j++;
	}
	if (tmp[j - 1] != '\0')
		tmp[j]= '\0';
	return (tmp);
}

char*	start_nextline(char *buf_cpy, char *line_start)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (buf_cpy[i] != '\n')
		i++;
	i++;
	line_start = (char *)malloc(sizeof(char) * (BUFFER_SIZE - i + 1));
	if (line_start == NULL)
		return (NULL);
	while (i + j < BUFFER_SIZE)
	{
		line_start[j] = buf_cpy[j + i];
		j++;
	}
	line_start[j] = '\0';
	return (line_start);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buf_cpy;
	static char	*line_start;
	char		*last_buf;
	char		*output;

if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
{
	free (line_start);
	//free (buf_cpy);
	line_start = NULL;
	//buf_cpy = NULL;
	return (NULL);
}
	if (line_start == 0)
	{
		printf("test");
		line_start = ft_strdup("");
	}
	line = ft_strjoin(line, line_start);
	buf_cpy = read_line(fd, &line, buf_cpy);
	if (ft_strchr(buf_cpy, '\n') != 0 || ft_strchr(buf_cpy, '\0') != 0)
	{
		last_buf = last_buffer(buf_cpy);
		/* if (last_buf == NULL)
			return (NULL); */
		line = ft_strjoin(line, last_buf);
		if (ft_strchr(buf_cpy, '\n') != 0)
			line_start = start_nextline(buf_cpy, line_start);
	}
	free (last_buf);
	free (buf_cpy);
	output = ft_strdup(line);
	free (line);
	return (output);
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
	close (fd);
	free (line);
	return (0);
}

