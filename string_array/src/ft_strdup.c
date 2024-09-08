/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 01:46:01 by mzurera-          #+#    #+#             */
/*   Updated: 2024/08/02 23:42:51 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_array_private.h"
#include <stdlib.h>

static void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*c_dest;
	char	*c_src;
	size_t	i;

	if (dest == NULL && src == NULL)
		return (NULL);
	c_dest = (char *) dest;
	c_src = (char *) src;
	i = 0;
	while (i < n)
	{
		c_dest[i] = c_src[i];
		++i;
	}
	return (dest);
}


static size_t	ft_strlen(const char *s)
{
	int	length;

	if (s == NULL)
		return (0);
	length = 0;
	while (s[length])
		++length;
	return (length);
}

static int	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	src_len;
	size_t	cpy_len;

	src_len = ft_strlen(src);
	if (size < 1)
		return (src_len);
	if (size <= src_len)
		cpy_len = size - 1;
	else
		cpy_len = src_len;
	ft_memcpy(dest, src, cpy_len);
	dest[cpy_len] = '\0';
	return (src_len);
}


char	*ft_strdup(const char *s)
{
	size_t	size;
	char	*str;

	size = ft_strlen(s) + 1;
	str = (char *) malloc(size);
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s, size);
	return (str);
}