/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschmitz <jschmitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 19:58:09 by jschmitz          #+#    #+#             */
/*   Updated: 2024/07/23 22:10:21 by jschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

char	*get_next_line(int fd)
{
	static char	*array_tmp_line[1024];
	char		*line;
	char		*buffer;

	line = NULL;
	if (fd < 0 || fd > 1023 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(array_tmp_line[fd]);
		free(line);
		array_tmp_line[fd] = NULL;
		line = NULL;
		return (NULL);
	}
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == 0)
		return (NULL);
	array_tmp_line[fd] = read_next_line(fd, array_tmp_line[fd], buffer);
	if (array_tmp_line[fd] == NULL)
		return (free(array_tmp_line[fd]), NULL);
	line = trim_start(array_tmp_line[fd], line);
	array_tmp_line[fd] = get_tmp_line(array_tmp_line[fd]);
	return (line);
}
// int	main (void)
// {
// 	char	*line;
// 	int		fd;
// 	char	*line1;
// 	int		fd1;
// 	char	*line2;
// 	int		fd2;
// 	char	*line3;
// 	int		fd3;
// 	char	*line4;
// 	int		fd4;

// 	fd = open("testfile.txt", O_RDONLY);
// 	if (fd == -1)
// 	{
// 		perror("open");
// 		return (1);
// 	}
// 	fd1 = open("testfile1.txt", O_RDONLY);
// 	if (fd1 == -1)
// 	{
// 		perror("open1");
// 		return (1);
// 	}
// 	fd2 = open("testfile2.txt", O_RDONLY);
// 	if (fd2 == -1)
// 	{
// 		perror("open2");
// 		return (1);
// 	}
// 	fd3 = open("testfile3.txt", O_RDONLY);
// 	if (fd3 == -1)
// 	{
// 		perror("open3");
// 		return (1);
// 	}
// 	fd4 = open("testfile4.txt", O_RDONLY);
// 	if (fd4 == -1)
// 	{
// 		perror("open4");
// 		return (1);
// 	}
// //	printf("test");
// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	free (line);
// 	line1 = get_next_line(fd1);
// 	printf("(1) %s", line1);
// 	free (line1);
// 	line2 = get_next_line(fd2);
// 	printf("(2) %s", line2);
// 	free (line2);
// 	line3 = get_next_line(fd3);
// 	printf("(3) %s", line3);
// 	line4 = get_next_line(fd4);
// 	printf("(4) %s", line4);
// 	free (line4);
// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	free (line);
// 	line1 = get_next_line(fd1);
// 	printf("(1) %s", line1);
// 	free (line1);
// 	line2 = get_next_line(fd2);
// 	printf("(2) %s", line2);
// 	free (line2);
// 	line3 = get_next_line(fd3);
// 	printf("(3) %s", line3);
// 	line4 = get_next_line(fd4);
// 	printf("(4) %s", line4);
// 	free (line4);
// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	free (line);
// 	line1 = get_next_line(fd1);
// 	printf("(1) %s", line1);
// 	free (line1);
// 	line2 = get_next_line(fd2);
// 	printf("(2) %s", line2);
// 	free (line2);
// 	line3 = get_next_line(fd3);
// 	printf("(3) %s", line3);
// 	line4 = get_next_line(fd4);
// 	printf("(4) %s", line4);
// 	free (line4);
// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	free (line);
// 	line1 = get_next_line(fd1);
// 	printf("(1) %s", line1);
// 	free (line1);
// 	line2 = get_next_line(fd2);
// 	printf("(2) %s", line2);
// 	free (line2);
// 	line3 = get_next_line(fd3);
// 	printf("(3) %s", line3);
// 	line4 = get_next_line(fd4);
// 	printf("(4) %s", line4);
// 	free (line4);
// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	free (line);
// 	line1 = get_next_line(fd1);
// 	printf("(1) %s", line1);
// 	free (line1);
// 	line2 = get_next_line(fd2);
// 	printf("(2) %s", line2);
// 	free (line2);
// 	line3 = get_next_line(fd3);
// 	printf("(3) %s", line3);
// 	line4 = get_next_line(fd4);
// 	printf("(4) %s", line4);
// 	free (line4);
// 	close (fd);
// 	close (fd1);
// 	close (fd2);
// 	close (fd3);
// 	close (fd4);
// 	return (0);
// }
