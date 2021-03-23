/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-der <mvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/01 10:26:16 by mvan-der      #+#    #+#                 */
/*   Updated: 2021/03/23 17:55:08 by mvan-der      ########   odam.nl         */
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
	line = 0;
	ret = get_next_line(fd, &line);
	// if (ret == -1)
	// {
	// 	printf("failure to read file\n");
	// 	return (0);
	// }
	// else
	// {
		// printf("line from main: %s\n", line);
	// printf("%d\n", ret);

	while (ret > 0)
	{
		write(1, line, strlen(line));
		write(1, "\n", 1);
		free(line);
		line = 0;
		ret = get_next_line(fd, &line);
	}
	if (ret == 0)
	{
		write(1, line, strlen(line));
		write(1, "\n", 1);
		free(line);
		line = 0;
	}
	if (ret == -1)
	{
		write(1, "Error!", 6);
		free(line);
	}

	// char			*lineadress[4];
	// int j = 1;
	// while ((ret = get_next_line(fd, &line)) > 0)
	// {
	// 	printf("|%s\n", line);
	// 	lineadress[j - 1] = line;
	// 	j++;
	// }
	// printf("|%s\n", line);
	// free(line);
	close(fd);
	// free(line);
	return (0);
}

