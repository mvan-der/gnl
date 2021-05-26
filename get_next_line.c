/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-der <mvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/25 13:18:17 by mvan-der      #+#    #+#                 */
/*   Updated: 2021/05/26 12:12:14 by mvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	i;
	size_t	check;

	check = ft_strlen(s);
	dest = malloc(sizeof(char) * len + 1);
	if (!dest)
		return (NULL);
	i = 0;
	if (start > check)
	{
		dest[i] = '\0';
		return (dest);
	}
	while (s[start] != '\0' && i < len)
	{
		dest[i] = s[start];
		i++;
		start++;
	}
	dest[i] = '\0';
	return (dest);
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
	int	i;

	i = 0;
	*line = ft_substr(result, 0, j);
	if (!*line)
	{
		free(result);
		return (-1);
	}
	if (result[j])
		j++;
	while (result[j] != '\0')
	{
		result[i] = result[j];
		i++;
		j++;
	}
	result[i] = '\0';
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
		buffer[ret] = '\0';
		result = gnl_strjoin(result, buffer);
		if (!result)
			return (-1);
		if (result && (find_newline(result) != -1))
			return (get_line(line, result, find_newline(result)));
	}
	*line = ft_strdup(result);
	free(result);
	result = NULL;
	if (!*line)
		return (-1);
	return (0);
}
