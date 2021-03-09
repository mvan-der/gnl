/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-der <mvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/24 11:23:29 by mvan-der      #+#    #+#                 */
/*   Updated: 2021/03/09 15:29:47 by mvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

size_t		ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	int		i;
	int		j;

	newstr = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (newstr == 0)
		return (0);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		newstr[j] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		newstr[j] = s2[i];
		i++;
		j++;
	}
	if ((ft_strlen(s1) + ft_strlen(s2)) > 0)
		newstr[j] = '\0';
	return (newstr);
}

int	find_newline(char *buffer, int *found)
{
	int i;

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
