/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 15:33:07 by mzurera-          #+#    #+#             */
/*   Updated: 2024/08/24 22:41:15 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static int	index_list(int list[], int ordered[], unsigned int size)
{
	unsigned int	i;

	if (list == NULL || ordered == NULL || size == 0)
		return (0);
	i = 0;
	while (i < size)
	{
		list[i] = binary_search(ordered, size, list[i]);
		++i;
	}
	return (1);
}

static int	check_repetition(int nums[], unsigned int size)
{
	unsigned int	i;

	if (nums == NULL || size < 2)
		return (0);
	i = 1;
	while (i < size && nums[i] != nums[i - 1])
		i++;
	return (i != size);
}

static int	copy_list(int src[], int *dest[], unsigned int size)
{
	unsigned int	i;

	if (src == NULL || size == 0)
		return (0);
	*dest = malloc(sizeof(int) * size);
	if (*dest == NULL)
		return (0);
	i = 0;
	while (i < size)
	{
		(*dest)[i] = src[i];
		i++;
	}
	return (1);
}

/**
 * Parse the numbers and index them without repetition.
 * @return The stack on success, NULL otherwise.
 */
t_stack	*parse_numbers(t_stack *stack)
{
	int	*index;

	if (stack == NULL)
		return (NULL);
	if (!copy_list(stack->list, &index, stack->size))
		return (NULL);
	quicksort(index, 0, stack->size - 1);
	if (check_repetition(index, stack->size))
	{
		free_stack(stack);
		free(index);
		return (NULL);
	}
	if (!index_list(stack->list, index, stack->size))
	{
		free_stack(stack);
		free(index);
		return (NULL);
	}
	free(index);
	return (stack);
}