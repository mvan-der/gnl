/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-der <mvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/24 11:22:26 by mvan-der      #+#    #+#                 */
/*   Updated: 2021/05/26 12:11:55 by mvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# include <stddef.h>

int		get_next_line(int fd, char **line);
int		get_line(char **line, char *result, int j);
int		find_newline(char *buffer);
char	*ft_substr(const char *s, unsigned int start, size_t len);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup(const char *s);
char	*gnl_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *s);
size_t	ft_strcpy(char *dest, char *src);

#endif
