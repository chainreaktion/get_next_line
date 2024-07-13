/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschmitz <jschmitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 19:58:52 by jschmitz          #+#    #+#             */
/*   Updated: 2024/07/13 22:25:00 by jschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 20

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_list
{
	char			content[BUFFER_SIZE];
	struct s_list	*next;
}					t_list;

char	*get_next_line(int fd);


# endif
