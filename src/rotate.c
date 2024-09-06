/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 01:46:01 by mzurera-          #+#    #+#             */
/*   Updated: 2024/08/02 23:42:51 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_movements_aux(t_stack *stack_a, t_stack *stack_b,
	int moves[2], int print)
{
	while (moves[0] > 0)
	{
		ra(stack_a, stack_b, print);
		--moves[0];
	}
	while (moves[1] > 0)
	{
		rb(stack_a, stack_b, print);
		--moves[1];
	}
	while (moves[0] < 0)
	{
		rra(stack_a, stack_b, print);
		++moves[0];
	}
	while (moves[1] > 0)
	{
		rrb(stack_a, stack_b, print);
		++moves[1];
	}
}

static void	rotate_movements(t_stack *stack_a, t_stack *stack_b,
	int moves[2], int print)
{
	while (moves[0] > 0 && moves[1] > 0)
	{
		rr(stack_a, stack_b, print);
		--moves[0];
		--moves[1];
	}
	while (moves[0] < 0 && moves[1] < 0)
	{
		rrr(stack_a, stack_b, print);
		++moves[0];
		++moves[1];
	}
	rotate_movements_aux(stack_a, stack_b, moves, print);
}


/**
 * Move an stack_a index and its expected position in stack_b to the top
 * in minimum rotations, stack_b must be sorted.
 */
void	rotate(t_stack *stack_a, t_stack *stack_b, int index_a, int print)
{
	int	index_b;
	int	moves[2];
	int	curr_cost;

	index_b = binary_search(stack_b->list, stack_b->len, stack_a->list[index_a]);
	curr_cost = ft_max(index_a, index_b);
	moves[0] = index_a;
	moves[1] = index_b;
	if (curr_cost > (int) (index_a + stack_b->len - index_b))
	{
		moves[1] = -index_b;
		curr_cost = index_a + stack_b->len - index_b;
	}
	if (curr_cost > (int) (stack_a->len - index_a + index_b))
	{
		moves[0] = -index_a;
		moves[1] = index_b;
		curr_cost = stack_a->len - index_a + index_b;
	}
	if (curr_cost > ft_max(stack_a->len - index_a, stack_b->len - index_b))
	{
		moves[0] = -index_a;
		moves[1] = -index_b;
	}
	rotate_movements(stack_a, stack_b, moves, print % 2);
}