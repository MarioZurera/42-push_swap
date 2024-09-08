/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_string_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 01:46:01 by mzurera-          #+#    #+#             */
/*   Updated: 2024/08/02 23:42:51 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_array_private.h"

t_str_array *map_string_array(t_str_array *array, char *(*f)(char *))
{
	int	i;

	i = -1;
	while (array->strings[++i] != NULL)
		array->strings[i] = f((char *) array->strings[i]);
	return (array);
}
