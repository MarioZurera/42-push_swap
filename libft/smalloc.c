/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smalloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 19:19:56 by mzurera-          #+#    #+#             */
/*   Updated: 2023/09/12 19:19:57 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*smalloc(size_t size)
{
	void	*array;

	array = malloc(size);
	if (array == NULL)
	{
		write(2, "[ABORT]: Invalid malloc: Out of memory\n", 40);
		exit(1);
	}
	return (array);
}
