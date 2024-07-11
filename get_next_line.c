/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschmitz <jschmitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 19:58:09 by jschmitz          #+#    #+#             */
/*   Updated: 2024/07/11 20:03:12 by jschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*line;
	//static car so that at the next call the next line is given, not the same
	int		length;

	length = line_length(&length)
	open O_RDONLY
	//read
	//then copy buf to line
	//until line break
	line = (char *)malloc(sizeof(char) * nbyte + 1)
	//nbyte is the buffer size and it's given with the function call..?
	//read returns -1 if there is an error
	return (line)
	//sends bqck the pointer to the string containing the line it just read
	//when read returns "0" this mean it's the end of the file
}
int	main (int argc, char **argv)
{
//make a main that reads line per line until the end
//while (get_next_line != 0)
char *input;
char *line;


fd = argv[1]
line = get_next_line(input)

}
