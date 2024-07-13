/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschmitz <jschmitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 19:58:09 by jschmitz          #+#    #+#             */
/*   Updated: 2024/07/13 22:39:16 by jschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	read_line(t_list buffer_set, int fd)
{
	int		read_output;
	char	buffer[BUFFER_SIZE];
	char 	*buf_cpy;
	t_list	new;

	while (ft_strchr(buffer, '\n') == 0)
	{
		read_output = read (fd, buffer, BUFFER_SIZE);
		if (read_output < 0)
		{
			ft_lstclear(buffer_set);
			return (-1);
		}
		if (read_output == 0)
			return (0);
		buf_cpy = strdup(buffer);
		new->content = buf_cpy;
		ft_lstadd_back(buffer_set, new);
	}
	print("buffer end: %s\n", buffer);
	print("buffercpy end: %s\n", buf_cpy);
	if (ft_strchr(buffer, '\n') != 0)
	
	return (read_output);
}

char	*get_next_line(int fd)
{
	char	*line;
	t_list	buffer_set;
	int		read_output;

	read_output = read_line(buffer_set, fd);
	if (read_output == -1)
	{
		ft_lstclear(buffer_set);
		return (NULL);
	}
	line = (char *)malloc(sizeof(char) * ((ft_lstsize(buffer_set) - 1) * BUFFER_SIZE) + ft_strlen(lastelement) + 1);
	if (line == NULL)
	{
		ft_lstclear(buffer_set);
		return (NULL);
	}
	make_line(&line, buffer_set);
	return (line);
}
int	main (void)
{
	int		fd;
	char	*buffer;

	fd = open("testfile.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		return (1);
	}
	buffer = get_next_line(fd);
	printf("Read one line: %s", buffer);
	close(fd);
	return (0);
}
