/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_i32_array.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 01:46:01 by mzurera-          #+#    #+#             */
/*   Updated: 2024/08/02 23:42:51 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_array_private.h"

void	free_i32_array(t_i32_array *array)
{
	if (array == NULL)
		return ;
	free(array->list);
	free(array);
}
