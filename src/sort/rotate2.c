/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 01:46:01 by mzurera-          #+#    #+#             */
/*   Updated: 2024/08/02 23:42:51 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	rotate2(t_stack *stack_a, t_stack *stack_b, int *moves)
{
	int	curr_cost;
	int	index_a;
	int	index_b;

	index_a = moves[0];
	index_b = moves[1];
	curr_cost = ft_max(index_a, index_b);
	if (curr_cost > (int)(index_b + stack_a->len - index_a))
	{
		moves[0] = index_a - stack_a->len;
		curr_cost = index_b + stack_a->len - index_a;
	}
	if (curr_cost > (int)(stack_b->len - index_b + index_a))
	{
		moves[0] = index_a;
		moves[1] = index_b - stack_b->len;
		curr_cost = stack_b->len - index_b + index_a;
	}
	if (curr_cost > ft_max(stack_a->len - index_a, stack_b->len - index_b))
	{
		moves[0] = index_a - stack_a->len;
		moves[1] = index_b - stack_b->len;
	}
}

/**
* Move a stack_a index and its expected position in stack_b to the top
 * in minimum rotations, stack_b must be sorted.
 */
void	rotate(t_stack *stack_a, t_stack *stack_b, int index_b, int print)
{
	int	index_a;
	int	moves[2];

	index_a = next_element_index(stack_a->list, stack_a->len,
			stack_b->list[index_b]);
	moves[0] = index_a;
	moves[1] = index_b;
	rotate2(stack_a, stack_b, moves);
	rotate_movements(stack_a, stack_b, moves, print % 2);
}
