/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_tester.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschmitz <jschmitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 21:39:52 by jschmitz          #+#    #+#             */
/*   Updated: 2024/07/13 21:08:49 by jschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "get_next_line.h"

int	test_nextbuf(int file_des, char **buffercpy)
{
	ssize_t	bytes_read;
	char	buffer[BUFFER_SIZE];
	int		i = 0;
	int		buf_size = BUFFER_SIZE;
	printf("before malloc");
	*buffercpy = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (*buffercpy == NULL)
	{
		perror("read");
		close (file_des);
		return (-1);
	}
	bytes_read = read (file_des, buffer, buf_size - 1);
	if (bytes_read == -1)
	{
		perror("read");
		close (file_des);
		return (-1);
	}
	if (strchr(buffer, '\n') != 0)
	{
		while (buffer[i] != '\n')
			i++;
		bytes_read = i++;
	}
	buffer[bytes_read] = '\0';
	//close (file_des);
	*buffercpy = strdup(buffer);
	printf("buffercpy %s\n", *buffercpy);
	return (bytes_read);
}
char	*test_nextline(int file_des)
{
	char **buff_array;
	char *line;
	int	i = 0;
	int	j = 0;

	printf("beginning");
	while (test_nextbuf(file_des, &buff_array[i]) == BUFFER_SIZE)
		i++;
	buff_array[i + 1] = NULL;
	line = (char *)malloc(sizeof(char) * (BUFFER_SIZE * (i - 1) + 1));
	if (line == NULL)
		return (NULL);
	while (j < i)
	{
		strcat(line, buff_array[j]);
		j++;
	}
	return (line);
}

int	main(void)
{
	int		file_des;
	char 	*test;

	file_des = open("testfile.txt", O_RDONLY);
	if (file_des == -1)
	{
		perror("open");
		return (1);
	}
	test = test_nextline(file_des);
	printf("Read: %s", test);
/* 	buffer = test_nextline(file_des);
	printf("%s", buffer);
	buffer = test_nextline(file_des);
	printf("%s", buffer);
	buffer = test_nextline(file_des);
	printf("%s", buffer);
	buffer = test_nextline(file_des);
	printf("%s", buffer);
	buffer = test_nextline(file_des);
	printf("%s", buffer);
	buffer = test_nextline(file_des);
	printf("%s", buffer);
	buffer = test_nextline(file_des);
	printf("%s", buffer);
	buffer = test_nextline(file_des);
	printf("%s", buffer);
	buffer = test_nextline(file_des);
	printf("%s", buffer);
	buffer = test_nextline(file_des);
	printf("%s", buffer);
	buffer = test_nextline(file_des);
	printf("%s", buffer);
	buffer = test_nextline(file_des);
	printf("%s", buffer);
	close (file_des); */
	return (0);
}
