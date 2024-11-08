/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschmitz <jschmitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 19:58:52 by jschmitz          #+#    #+#             */
/*   Updated: 2024/07/23 22:10:51 by jschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 30
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdint.h>
# include <unistd.h>

char	*get_next_line_bonus(int fd);
char	*read_next_line(int fd, char *tmp_line, char *buf);
char	*get_tmp_line(char *tmp_line);
char	*trim_start(char *tmp_line, char *line);
size_t	ft_strlen(const char *s);
char	*ft_strchr(char *s, int c);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char *s1, char const *s2);

#endif
