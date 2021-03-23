/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gnltest.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-der <mvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/23 12:49:54 by mvan-der      #+#    #+#                 */
/*   Updated: 2021/03/23 17:52:48 by mvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int	find_newline(char *buffer, int *found)
{
	int	i;

	i = 0;
	*found = 0;
	while (buffer[i] && i < BUFFER_SIZE)
	{
		if (buffer[i] == '\n')
		{
			*found = 1;
			break ;
		}
		i++;
	}
	return (i);
}

int	get_next_line(int fd, char **line)
{
	int ret;
	static char	buffer[BUFFER_SIZE + 1];
	int found;
	int j;

	ft_memset(buffer, 0, BUFFER_SIZE + 1);
	ret = 999;
	found = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || !line)
		return (-1);
	// printf("char 0: %c\n", buffer[0]);
	// write(1, &buffer[0], 1);

	while (ret > 0)
	{
		if (buffer[0] != 'z')
		{
			printf("check12\n");
			printf("buffer: %s\n", buffer);
			j = find_newline(buffer, &found);
			if (found == 1)
			{
				*line = ft_strjoin(*line, ft_substr(buffer, 0, j));
				ft_memmove(&buffer[0], &buffer[j + 1], 33 - j);
				return (found);
			}
			if (found == 0)
			{
				*line = ft_strdup(buffer);
				ft_memset(buffer, 0, BUFFER_SIZE + 1);
			}
		}
		ret = read(fd, buffer, BUFFER_SIZE);
		if (ret > 0)
		{
			printf("check34\n");
			j = find_newline(buffer, &found);
			if (found == 1)
			{
				*line = ft_strjoin(*line, ft_substr(buffer, 0, j));
				ft_memmove(&buffer[0], &buffer[j + 1], 33 - j);
				printf("buffer..?: %s\n", buffer);
				// ft_memset(&buffer[j], 0, ft_strlen(buffer) - j);
				return (found);
			}
			if (found == 0)
			{
				*line = ft_strjoin(*line, buffer);
			}
		}
	}
	if (ret == 0)
	{
		printf("check56\n");
		j = find_newline(buffer, &found);
		if (found == 1)
		{
			ft_strjoin(*line, ft_substr(buffer, 0, j));
			ft_memmove(&buffer[0], &buffer[j + 1], 33 - j);
			// ft_memset(&buffer[j], 0, ft_strlen(buffer) - j);
			return (found);
		}
		if (found == 0)
		{
			*line = ft_strjoin(*line, buffer);
			return (found);
		}
	}
	return (0);
}
