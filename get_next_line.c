/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-der <mvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/24 11:21:53 by mvan-der      #+#    #+#                 */
<<<<<<< HEAD
/*   Updated: 2021/03/16 17:38:28 by mvan-der      ########   odam.nl         */
=======
/*   Updated: 2021/03/09 20:39:32 by mvan-der      ########   odam.nl         */
>>>>>>> 483045856b8a1ff589fdb941f6050d812976d0c1
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
	if (fd < 0 || BUFFER_SIZE <= 0 || !line)
		return (-1);
<<<<<<< HEAD
	// step 1: check buffer if there is still something in it, if yes then  check buffer for newline
	// 			and return (1) if found, if not found strdup/strjoin, memmove buffer accordingly
	// step 2: read into buffer
	// step 3: check for newline in buffer
	// step 4: if found, strjoin up until newline into *line, shift remainder to first position in buffer
	// step 5: if not found, go back to step 1
	
	// step 1
	if (*line) //find  newline before  next read
	{
=======
	ft_memset(buffer, 0, BUFFER_SIZE + 1);
	while (read_ret > 0)
	{
		read_ret = read(fd, buffer, BUFFER_SIZE);
		if (read_ret == 0)
			break ;
>>>>>>> 483045856b8a1ff589fdb941f6050d812976d0c1
		j = find_newline(buffer, &found);
		if (found == 1)
		{
			*line = ft_strjoin(*line, ft_substr(buffer, 0, j));
			ft_memmove(&buffer[0], &buffer[j + 1], ft_strlen(buffer) - j);
			return(found);
		}
		// *line = ft_strjoin(*line, buffer); 
	}
	if (!*line)
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
	printf("buffer: %s\n", buffer);
	// step 3
	j = find_newline(buffer, &found);
	// step 4
	if (found == 1)
	{
		*line = ft_strjoin(*line, ft_substr(buffer, 0, j));
		temp = ft_substr(buffer, j + 1, ft_strlen(buffer) - j);
		// ft_memmove(&buffer[0], &buffer[j + 1], ft_strlen(buffer) - j);
		return(found);
	}
	return (0);
}
