/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-der <mvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/01 10:26:16 by mvan-der      #+#    #+#                 */
/*   Updated: 2021/03/09 12:48:28 by mvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
	char *file_name;
	char *line;
	int ret;
	file_name = "testink123.txt";
	int fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		printf("failure to open file\n");
		return (0);
	}
	else
	{
		printf("open success!\n");
	}
	ret = get_next_line(fd, &line);
	if (ret == -1)
	{
		printf("failure to read file\n");
		return (0);
	}
	else
	{
		printf("line from main: %s\n", line);
	}
	return (0);
}

