/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-der <mvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/24 11:23:29 by mvan-der      #+#    #+#                 */
/*   Updated: 2021/03/09 12:08:41 by mvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stddef.h>

size_t		ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	find_newline(char *buffer)
{
	int i;
	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			break ;
			i++;
	}
	return (i);
}
