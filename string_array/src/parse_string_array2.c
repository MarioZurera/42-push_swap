/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_string_array.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 01:46:01 by mzurera-          #+#    #+#             */
/*   Updated: 2024/08/02 23:42:51 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_array_private.h"

void	check_oob(long num, t_str_array *array, t_i32_array	*result)
{
	if (num < INT_MIN || num > INT_MAX)
	{
		result->free(result);
		array->free(array);
		write(2, "Error\n", 6);
		exit(1);
	}
}
