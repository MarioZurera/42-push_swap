/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_string_array.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 01:46:01 by mzurera-          #+#    #+#             */
/*   Updated: 2024/08/02 23:42:51 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_array_private.h"
#include "string_array.h"
#include <unistd.h>
#include <stdlib.h>

static void	*smalloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (ptr == NULL)
	{
		write(2, "[ABORT]: Invalid malloc: Out of memory\n", 40);
		exit(1);
	}
	return (ptr);
}

static char	**ft_deep_copy(char **array, int size)
{
	char	**result;
	int		i;

	result = smalloc((size + 1) * sizeof(char *));
	i = -1;
	while (++i < size)
		result[i] = ft_strdup(array[i]);
	result[i] = NULL;
	return (result);
}

static int	get_size(const char **array)
{
	int	size;

	size = 0;
	while (array[size] != NULL)
		size++;
	return (size);
}

t_str_array	*string_array_from(const char **array)
{
	t_str_array	*result;

	result = smalloc(sizeof(t_str_array));
	result->strings = ft_deep_copy(array, get_size(array));
	result->get = &get_string_array;
	result->len = &len_string_array;
	result->free = &free_string_array;
	result->clone = &clone_string_array;
	result->map = &map_string_array;
	result->every = &every_string_array;
	result->parse = &parse_string_array;
	return (result);
}

t_str_array	*string_array_empty()
{
	char	**array;

	array = smalloc(sizeof(char *));
	array[0] = NULL;
	return (string_array_from(array));
}
