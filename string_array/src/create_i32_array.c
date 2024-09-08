/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clone_string_array.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 01:46:01 by mzurera-          #+#    #+#             */
/*   Updated: 2024/08/02 23:42:51 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_array_private.h"
#include "string_array.h"

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

static void	*ft_memset(void	*s, int c, size_t n)
{
	char	*memory;
	size_t	i;

	memory = (char *) s;
	i = 0;
	while (i < n)
		memory[i++] = c;
	return (s);
}

t_i32_array	*create_i32_array(size_t size)
{
	t_i32_array	*result;

	result = smalloc(sizeof(t_i32_array));
	result->size = size;
	result->list = smalloc(size * sizeof(int));
	ft_memset(result->list, 0, size * sizeof(int));
	result->free = &free_i32_array;
	return (result);
}