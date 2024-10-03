/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 18:06:10 by mzurera-          #+#    #+#             */
/*   Updated: 2024/08/03 14:37:27 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	min_movs_rotate(t_stack *stack_a, t_stack *stack_b)
{
	int	rotations_b;
	int	b_curr_rots;
	int	cost;
	int tmp_cost;

	rotations_b = 0;
	b_curr_rots = -1;
	cost = 0;
	while (++b_curr_rots < (int) stack_b->len)
	{
		tmp_cost = get_rotations_cost(stack_b, stack_a, b_curr_rots);
		if (tmp_cost < cost)
		{
			rotations_b = b_curr_rots;
			cost = tmp_cost;
		}
	}
	rotate(stack_b, stack_a, rotations_b, 1);
}

int	get_max_index(int *arr, int size)
{
	int	i;
	int	max;
	int	max_i;

	i = -1;
	max_i = 0;
	max = INT_MIN;
	while (++i < size) {
		if (arr[i] > max)
		{
			max = arr[i];
			max_i = i;
		}
	}
	return (max_i);
}


void print_stack(t_stack *stack) {
	for (unsigned i = 0; i < stack->len; i++) {
		ft_printf("%d | ", stack->list[i]);
	}
	ft_printf("\n");
}

void	greedy_algorithm(t_stack *stack_a, t_stack *stack_b)
{
	// Find longest already sorted segment in A (avoid pushing into B)
	while (stack_a->len > 3)
			pb(stack_a, stack_b, 1);
	sort3(stack_a);
	while (stack_b->len > 0) {
		min_movs_rotate(stack_a, stack_b);
		pa(stack_a, stack_b, 1);
	}
	sort_partial_ordered_stack_a(stack_a);
}
