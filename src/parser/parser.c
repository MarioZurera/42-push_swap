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

static void	check_repetition(int *nums, unsigned int size)
{
	unsigned int	i;

	i = 1;
	while (i < size && nums[i] != nums[i - 1])
		i++;
	if (i != size)
		push_swap_error();
}

static int	*populate_from(int *dest, int *src, unsigned int size)
{
	int	i;

	i = -1;
	while (++i < (int) size)
		dest[i] = src[i];
	return (dest);
}

static int	*index_list(int *list, unsigned int size)
{
	int	*index;
	int	i;

	index = smalloc(size * sizeof(int));
	index = populate_from(index, list, size);
	index = quicksort(index, 0, size - 1);
	i = -1;
	while (++i < (int) size)
		list[i] = binary_search(index, size, list[i]);
	free(index);
	return (list);
}

/**
 * Index numbers without repetition.
 */
t_stack	*parse_numbers(t_stack *stack)
{
	stack->list = index_list(stack->list, stack->len);
	check_repetition(stack->list, stack->len);
	return (stack);
}
