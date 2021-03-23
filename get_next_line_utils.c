/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-der <mvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/24 11:23:29 by mvan-der      #+#    #+#                 */
/*   Updated: 2021/03/23 17:00:12 by mvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

size_t	ft_strlen(const char *s)
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
	int		s1fail;

	if (!s1)
	{
		s1fail = 0;
	}
	else
	{
		s1fail = ft_strlen(s1);
	}
	newstr = malloc(s1fail + ft_strlen(s2) + 1);
	if (!newstr)
		return (NULL);
	if (!s1)
	{
		ft_strlcpy(newstr, s2, ft_strlen(s2) + 1);
	}
	else
	{
		ft_strlcpy(newstr, s1, ft_strlen(s1) + 1);
		ft_strlcat(newstr, s2, s1fail + ft_strlen(s2) + 1);
	}
	return (newstr);
}

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*a;

	i = 0;
	a = s;
	while (i < n)
	{
		a[i] = (unsigned char)c;
		i++;
	}
	return (a);
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

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*ptr;
	size_t			i;

	if (nmemb == 0 || size == 0)
	{
		nmemb = 1;
		size = 1;
	}
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < (nmemb * size))
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!src)
		return (0);
	if (size == 0)
		return (ft_strlen(src));
	while (src[i] != '\0' && i < (size - 1))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	destlen;
	size_t	i;

	i = 0;
	destlen = ft_strlen(dest);
	if (size > destlen)
	{
		while (src[i] != '\0' && i < (size - destlen - 1))
		{
			dest[destlen + i] = src[i];
			i++;
		}
		dest[destlen + i] = '\0';
		return (destlen + ft_strlen(src));
	}
	return (size + ft_strlen(src));
}
