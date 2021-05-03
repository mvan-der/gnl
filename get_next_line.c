/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-der <mvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/25 13:18:17 by mvan-der      #+#    #+#                 */
/*   Updated: 2021/05/03 16:59:27 by mvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	fix_buffer(char *buffer, int k)
{
	int	i;

	i = 0;
	if (buffer[k])
		k++;
	while (buffer[k] != '\0')
	{
		buffer[i] = buffer[k];
		i++;
		k++;
	}
	buffer[i] = '\0';
}

int	find_newline(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (-1);
	while (s[i] && (s[i] != '\n'))
		i++;
	if (s[i] != '\n')
		return (-1);
	return (i);
}

int	get_line(char **line, char *result, int j)
{
	*line = ft_substr(result, 0, j);
	fix_buffer(result, j);
	return (1);
}

int	get_next_line(int fd, char **line)
{
	int			ret;
	char		buffer[BUFFER_SIZE + 1];
	static char	*result;

	ret = 999;
	if (fd < 0 || BUFFER_SIZE <= 0 || !line || read(fd, 0, 0) < 0)
		return (-1);
	if (result && (find_newline(result) != -1))
		return (get_line(line, result, find_newline(result)));
	while (ret > 0)
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		if (ret == -1)
			return (ret);
		buffer[ret] = '\0';
		result = gnl_strjoin(result, buffer);
		if (result && (find_newline(result) != -1))
			return (get_line(line, result, find_newline(result)));
	}
	*line = ft_strdup(result);
	free(result);
	result = NULL;
	return (0);
}
