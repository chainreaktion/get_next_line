/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johanna <johanna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 19:58:09 by jschmitz          #+#    #+#             */
/*   Updated: 2024/11/07 13:15:41 by johanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//reads the line and returns it to the main function (incl. start next line)
char	*read_next_line(int fd, char *tmp_line, char *buffer)
{
	ssize_t	read_bytes;

	read_bytes = 1;
	if (tmp_line == NULL)
		tmp_line = ft_strdup("\0");
	while (read_bytes > 0)
	{
		read_bytes = read (fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
			return (free(buffer), NULL);
		buffer[read_bytes] = '\0';
		tmp_line = ft_strjoin(tmp_line, buffer);
		if (read_bytes == 0 && tmp_line[0] == 0)
			return (free(buffer), free(tmp_line), NULL);
		if (ft_strchr(buffer, '\n') != 0)
			break ;
	}
	return (free(buffer), tmp_line);
}

//extracts the start for the next line from the last buffer
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
	return (free(tmp_line), tmp_new);
}

//if tmp_line is empty, the end if the file is reached and GNL should return
//	NULL (no next line)
//This function removes the start of the next line after the \n or trims
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

/* char	*get_next_line(int fd)
{
	static char	*tmp_line;
	char		*line;
	char		*buffer;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(tmp_line);
		free(line);
		tmp_line = NULL;
		line = NULL;
		return (NULL);
	}
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == 0)
		return (NULL);
	tmp_line = read_next_line(fd, tmp_line, buffer);
	if (tmp_line == NULL)
		return (free(tmp_line), NULL);
	line = trim_start(tmp_line, line);
	tmp_line = get_tmp_line(tmp_line);
	return (line);
} */
char	*get_next_line(int fd)
{
	static char	*tmp_line;
	char		*line;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == 0)
		return (0);
	line = read_next_line(fd, tmp_line, buffer);
	free(buffer);
	if (line == NULL)
		return (NULL);
	line = trim_start(tmp_line, line);
	tmp_line = get_tmp_line(tmp_line);
	return (line);
}
// int	main (void)
// {
// 	char	*line;
// 	int		fd;

// 	fd = open("testfile.txt", O_RDONLY);
// 	if (fd == -1)
// 	{
// 		perror("open");
// 		return (1);
// 	}
// //	printf("test");
// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	free (line);
// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	free (line);
// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	free (line);
// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	close (fd);
// 	free (line);
// 	return (0);
// }
