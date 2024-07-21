/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschmitz <jschmitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 19:58:09 by jschmitz          #+#    #+#             */
/*   Updated: 2024/07/21 23:47:11 by jschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//reads the line and returns it to the main fct
//
char	*read_next_line(int fd, char *tmp_line, char *buffer)
{
	ssize_t	read_bytes;

	read_bytes = 1;
	if (tmp_line == NULL)
		tmp_line = ft_strdup("");
	while (read_bytes > 0)
	{
		read_bytes = read (fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
			return (free(buffer), NULL);
		buffer[read_bytes] = '\0';
		tmp_line = ft_strjoin(tmp_line, buffer);
		if (ft_strchr(buffer, '\n') == 0)
			break ;
	}
	return (free(buffer), tmp_line);
}

char	*get_tmp_line(char *tmp_line)
{
	int		len;
	int		i;
	char	*tmp_new;

	len = 0;
	i = 0;
	if (tmp_line == NULL)
		return (NULL);
	while (tmp_line[len] != '\n' && tmp_line[len] != '\0')
		len++;
	if (tmp_line[len] == '\n')
		len++;
	tmp_new = (char *)malloc(sizeof(char) * (ft_strlen(tmp_line) + 1));
	if (tmp_new == NULL)
		return (NULL);
	while (tmp_line[len + i] != '\0')
	{
		tmp_new[i] = tmp_line[len + i];
		i++;
	}
	tmp_new[i] = '\0';
	//return (free(tmp_line), tmp_new);
	return (tmp_line);
}

//if tmp_line is NULL, the end if the file is reached and
//	GNL should return NULL (no next line)
//if malloc fails, GNL should return NULL (error)
char	*trim_start(char *tmp_line, char *line)
{
	int	len;
	int	i;

	if (tmp_line == NULL)
		return (NULL);
	len = 0;
	i = 0;
	while (tmp_line[len] != '\n' && tmp_line[len] != '\0')
		len++;
	if (tmp_line[len] == '\n')
		len++;
	line = (char *)malloc (sizeof(char) * (len + 1));
	if (line == NULL)
		return (NULL);
	while (i < len)
	{
		line[i] = tmp_line[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*tmp_line;
	char		*line;
	char		*buffer;

	line = NULL;
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(tmp_line);
		free(line);
		tmp_line = NULL;
		line = NULL;
		return (NULL);
	}
	if (buffer == 0)
		return (NULL);
	tmp_line = read_next_line(fd, tmp_line, buffer);
	if (tmp_line == NULL)
		return (NULL);
	line = trim_start(tmp_line, line);
	tmp_line = get_tmp_line(tmp_line);
	return (line);
}
/*
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
	line = get_next_line(fd);
	printf("%s", line);
	close (fd);
	free (line);
	return (0);
}
 */
