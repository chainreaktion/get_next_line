/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschmitz <jschmitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 17:13:00 by jschmitz          #+#    #+#             */
/*   Updated: 2024/07/20 19:06:52 by jschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s) + i);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)(s) + i);
	return (0);
}

int	ft_strdup(const char *s, char **cpy)
{
	size_t		i;

	//check that the string s and the pointer to the copy are valid
	if (s == NULL || cpy == NULL)
		return (-1);
	*cpy = malloc (sizeof(char) * (ft_strlen(s) + 1));
	if (*cpy == NULL)
		return (-1);
	i = 0;
	while (s[i])
	{
		(*cpy)[i] = s[i];
		i++;
	}
	(*cpy)[i] = '\0';
	return (0);
}

int	ft_strjoin(char const *s1, char const *s2, char **res)
{
	size_t	i;
	size_t	len_s1;
	size_t	len_s2;

	if (s1 == NULL || s2 == NULL || res == NULL)
		return (-1);
	i = 0;
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	*res = malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (*res == NULL)
		return (-1);
	while (i < len_s1)
	{
		(*res)[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < len_s2)
	{
		(*res)[i + len_s1] = s2[i];
		i++;
	}
	(*res)[i + len_s1] = '\0';
	return (free (s1), free (s2), 0);
}
int	border_case(char *line_start, char **line, char **buf_cpy)
{
	int	return_val;

	if (ft_strchr(line_start, '\0') != 0)
		return_val = last_buffer(line_start, buf_cpy)


	last_buf = last_buffer(buf_cpy);

		return (char *last_buf, char **tmp)
	else if (ft_strchr(line_start, '\n') != 0)
	{
		return_val = strdup(line_start, buf_cpy);
		if (return_val == -1)
			return (-1);
		return_val = start_nextline(buf_cpy, line_start)
		return (return_val);
	}


}
