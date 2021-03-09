/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-der <mvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/24 11:21:53 by mvan-der      #+#    #+#                 */
/*   Updated: 2021/03/09 20:39:32 by mvan-der      ########   odam.nl         */
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
	char		buffer[BUFFER_SIZE + 1];
	static char	*remainder;
	int			found;
	size_t		j;
	int i = 0;
	read_ret = 999;
	found = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || !line)
		return (-1);
	ft_memset(buffer, 0, BUFFER_SIZE + 1);
	while (read_ret > 0)
	{
		read_ret = read(fd, buffer, BUFFER_SIZE);
		if (read_ret == 0)
			break ;
		j = find_newline(buffer, &found);
		if (found == 0)
			remainder = ft_strdup(buffer);
		if (found == 1)
		{
			*line = ft_strjoin(remainder, ft_substr(buffer, 0, j));
			ft_memset(remainder, 0, ft_strlen(remainder));
			remainder = ft_substr(buffer, j + 1, ft_strlen(buffer) - j);
		}
		printf("remainder %d: %s\n", i, remainder);
		i++;
	}
	return (read_ret);
}
