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

#include "../../includes/push_swap.h"

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
	while (moves[1] < 0)
	{
		rrb(stack_a, stack_b, print);
		++moves[1];
	}
}

void	rotate_movements(t_stack *stack_a, t_stack *stack_b,
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

void	rotate_a(t_stack *stack_a, int moves)
{
	if (moves > (int) stack_a->len / 2)
		moves -= (int) stack_a->len;
	rotate_movements(stack_a, NULL, (int []){moves, 0}, 1);
}

int	next_element_index(int *arr, int size, int value)
{
	int	index;
	int	min_index;

	index = 0;
	min_index = get_min_index(arr, size);
	if (value > arr[size - 1] && index < min_index)
	{
		while (index < min_index)
		{
			if (value < arr[index])
				return (index);
			index++;
		}
		return (min_index);
	}
	index = min_index;
	while (index < size)
	{
		if (value < arr[index])
			return (index);
		index++;
	}
	return (min_index);
}

int	get_rotations_cost(t_stack *stack_a, t_stack *stack_b, int index_b)
{
	int	index_a;
	int	curr_cost;

	index_a = next_element_index(stack_a->list, stack_a->len,
			stack_b->list[index_b]);
	curr_cost = ft_max(index_a, index_b);
	if (curr_cost > (int)(index_b + stack_a->len - index_a))
	{
		curr_cost = (int)(index_b + stack_a->len - index_a);
	}
	if (curr_cost > (int)(stack_b->len - index_b + index_a))
	{
		curr_cost = (int)(stack_b->len - index_b + index_a);
	}
	if (curr_cost > ft_max(stack_a->len - index_a, stack_b->len - index_b))
	{
		curr_cost = ft_max(stack_a->len - index_a, stack_b->len - index_b);
	}
	return (curr_cost);
}
