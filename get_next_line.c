/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-der <mvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/24 11:21:53 by mvan-der      #+#    #+#                 */
/*   Updated: 2021/03/23 12:49:17 by mvan-der      ########   odam.nl         */
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
	int			read_ret;
	static char	buffer[BUFFER_SIZE + 1];
	char		*temp;
	int			found;
	int		j;

	ft_memset(buffer, 0, BUFFER_SIZE + 1);
	read_ret = 999;
	found = 0;
	temp = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || !line)
		return (-1);
	// step 1: check buffer if there is still something in it, if yes then  check buffer for newline
	// 			and return (1) if found, if not found strdup/strjoin, memmove buffer accordingly
	// step 2: read into buffer
	// step 3: check for newline in buffer
	// step 4: if found, strjoin up until newline into *line, shift remainder to first position in buffer
	// step 5: if not found, go back to step 1
	
	// step 1
	if (*line) //find  newline before  next read
	{
		j = find_newline(temp, &found);
		if (found == 1)
		{
			*line = ft_strjoin(*line, ft_substr(buffer, 0, j));
			ft_memmove(&temp[0], &temp[j + 1], ft_strlen(temp) - j);
			return(found);
		}
		// *line = ft_strjoin(*line, buffer); 
	}
	if (!*line) //?? first time calling the function is the only time this true at which point buffer is also empty..? removing causes seg fault
	{
		*line = ft_strdup(buffer);
	}
	// printf("line1: %s\n", *line);
	// printf("buffer: %s\n", buffer);
	// step 2
	ft_memset(buffer, 0, BUFFER_SIZE + 1);
	read_ret = read(fd, buffer, BUFFER_SIZE);
	if (read_ret == -1)
		return (-1);
	// step 3
	j = find_newline(buffer, &found);
	// step 4
	if (found == 1)
	{
		*line = ft_strjoin(*line, ft_substr(buffer, 0, j));
		temp = ft_substr(buffer, j + 1, ft_strlen(buffer) - j);
		printf("temp: %s\n", temp);
		// ft_memmove(&buffer[0], ;&buffer[j + 1], ft_strlen(buffer) - j);
		return(found);
	}
	return (0);
}
