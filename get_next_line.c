/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-der <mvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/24 11:21:53 by mvan-der      #+#    #+#                 */
/*   Updated: 2020/12/01 11:09:37 by mvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

int		get_next_line(int fd, char **line)
{
	// return a line from a fd without newline
	// read until /n (or EOF if that's the case) and display whatever is read
	// loop it till EOF is reached

	// read(fd, temp, BUFFER_SIZE); ?
	int ret;
	if (fd < 0 || BUFFER_SIZE <= 0 || !line)
		return (-1);
	line = malloc(sizeof(line) * BUFFER_SIZE);
	ret = read(fd, line, BUFFER_SIZE);
	return (ret);
}
