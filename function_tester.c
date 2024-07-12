/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_tester.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschmitz <jschmitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 21:39:52 by jschmitz          #+#    #+#             */
/*   Updated: 2024/07/12 21:57:04 by jschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

char	*test_nextline(int file_des)
{
	ssize_t	bytes_read;
	char	buffer[10];
	int		i = 0;
	int		buf_size = 10;
	char	*buffercpy;

	bytes_read = read (file_des, buffer, buf_size - 1);
	if (bytes_read == -1)
	{
		perror("read");
		close (file_des);
		return (NULL);
	}
	if (strchr(buffer, '\n') != 0)
	{
		while (buffer[i] != '\n')
			i++;
		bytes_read = i++;
	}
	buffer[bytes_read] = '\0';
	//close (file_des);
	buffercpy = strdup(buffer);
	return (buffercpy);
}
int	main(void)
{
	int		file_des;
	char	*buffer;

	file_des = open("testfile.txt", O_RDONLY);
	if (file_des == -1)
	{
		perror("open");
		return (1);
	}
	buffer = test_nextline(file_des);
	printf("Read: %s", buffer);
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
	buffer = test_nextline(file_des);
	printf("%s", buffer);
	close (file_des);
	return (0);
}
