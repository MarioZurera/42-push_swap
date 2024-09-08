/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   every_string_array.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 01:46:01 by mzurera-          #+#    #+#             */
/*   Updated: 2024/08/02 23:42:51 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_array_private.h"

int	every_string_array(t_str_array *array, int *(*f)(char *))
{
	int	i;

	i = 0;
	while (array->strings[i] != NULL && f(array[i]) != 0)
		i++;
	return (array->strings[i] == NULL);
}
