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

static const char	**ft_deep_copy(const char **array, const int size)
{
	char	**result;
	int		i;

	result = smalloc((size + 1) * sizeof(char *));
	i = -1;
	while (++i < size)
		result[i] = ft_strdup(array[i]);
	result[i] = NULL;
	return ((const char **) result);
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
	const char	**array;

	array = smalloc(sizeof(char *));
	array[0] = NULL;
	return (string_array_from(array));
}
