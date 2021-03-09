/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-der <mvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/24 11:21:53 by mvan-der      #+#    #+#                 */
/*   Updated: 2021/03/09 14:45:53 by mvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*a;
	unsigned char	b;

	i = 0;
	a = s;
	b = 0;
	while (i < n)
	{
		a[i] = b;
		i++;
	}
}

char	*ft_strdup(const char *s)
{
	char	*dest;
	int		i;

	i = 0;
	while (s[i] != '\0')
		i++;
	dest = malloc(i + 1);
	if (dest == 0)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	i;
	size_t	check;

	check = ft_strlen(s);
	dest = malloc(sizeof(char) * len + 1);
	if (dest == 0)
		return (0);
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

int	get_next_line(int fd, char **line)
{
	int		ret;
	char	buffer[BUFFER_SIZE];
	static char	*remainder;
	
	ret = 999;
	if (fd < 0 || BUFFER_SIZE <= 0 || !line)
		return (-1);
	while (ret > 0)
	{
		if (remainder != 0)
		{
			*line = ft_strdup(remainder);
			ft_bzero(remainder, ft_strlen(remainder));
		}
		ret = read(fd, buffer, BUFFER_SIZE);
		printf("ret?: %d\n", ret);
		if (ret == 0)
			break ;
		int j = find_newline(buffer);
		*line = ft_substr(buffer, 0, j);
		printf("line: %s\n", *line);
		remainder = ft_substr(buffer, j + 1, ft_strlen(buffer) - j);
		printf("remainder: %s\n", remainder);
	}
	return (ret);
}
