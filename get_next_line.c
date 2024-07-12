/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschmitz <jschmitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 19:58:09 by jschmitz          #+#    #+#             */
/*   Updated: 2024/07/12 23:06:48 by jschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	calc_str_length(list)
{
//(number if elements in the liste -1) * buf_size + length string last list-element
}
//list free function

//add element function

//function concatenate strings from list and null-terminate(char *str, list_adress), takes address to allocated string

char	*get_next_line(int fd)
{
	static char	*line;
	int		length;

	length = line_length(&length)
	line = (char *)malloc(sizeof(char) * calc_str_length + 1);
	if (line == NULL)
	{
		free (list);
		return (NULL);
	}
	//nbyte is the buffer size and it's given with the function call..?
	//read returns -1 if there is an error
	return (line);
}
int	main (int argc, char **argv)
{
char *input;
char *line;


fd = argv[1]
line = get_next_line(input)

}
