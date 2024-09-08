/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_search.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 19:14:52 by mzurera-          #+#    #+#             */
/*   Updated: 2023/09/12 19:15:42 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	binary_search(int *arr, int size, int value)
{
	unsigned int	l;
	unsigned int	r;
	unsigned int	m;

	l = 0;
	r = size - 1;
	while (l <= r)
	{
		m = (l + r) / 2;
		if (arr[m] == value)
			return (m);
		if (arr[m] < value)
			l = m + 1;
		if (arr[m] > value)
			r = m - 1;
	}
	return (-1);
}
