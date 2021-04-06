/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-der <mvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/25 13:18:17 by mvan-der      #+#    #+#                 */
/*   Updated: 2021/04/06 16:58:02 by mvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*a;
	char	*b;
	size_t	i;

	a = (char *)dest;
	b = (char *)src;
	i = 0;
	if (src != 0 || dest != 0)
	{
		while (i < n)
		{
			a[i] = b[i];
			i++;
		}
		return (a);
	}
	return (a);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*dptr;
	const char	*sptr;
	char		*enddest;
	const char	*endsrc;

	dptr = dest;
	sptr = src;
	enddest = dptr + (n - 1);
	endsrc = sptr + (n - 1);
	if (dptr == NULL && sptr == NULL)
		return (0);
	if (enddest < endsrc)
	{
		ft_memcpy(dest, src, n);
		return (dest);
	}
	while (n)
	{
		*enddest = *endsrc;
		enddest--;
		endsrc--;
		n--;
	}
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
	*line = ft_substr(result, 0, j);
	ft_memmove(result, result + j + 1, (ft_strlen(result + j) + 1));
	return (1);
}

int	get_next_line(int fd, char **line)
{
	int			ret;
	char		buffer[BUFFER_SIZE + 1];
	static char	*result;

	ret = 999;
	if (fd < 0 || BUFFER_SIZE <= 0 || !line || read(fd, 0 , 0) < 0)
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
