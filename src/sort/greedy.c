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
	int	rotations_a;
	int	a_curr_rots;
	int	cost;
	int tmp_cost;

	if (stack_b->size == 0 || stack_b->len == 0)
		return ;
	rotations_a = 0;
	a_curr_rots = -1;
	cost = 0;
	while (++a_curr_rots < (int) stack_a->len)
	{
		tmp_cost = get_rotations_cost(stack_a, stack_b, a_curr_rots);
		if (tmp_cost < cost)
		{
			rotations_a = a_curr_rots;
			cost = tmp_cost;
		}
	}
	rotate(stack_a, stack_b, rotations_a, 1);
}

static int	get_max_index(int *arr, int size)
{
	int	i;
	int	max_i;
	int	max;

	i = -1;
	max_i = -1;
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

// static void	rotate_a(t_stack *stack_a, int min)
// {
// 	while (min--)
// 		ra(stack_a, NULL, 1);
// 	ra(stack_a, NULL, 1);
// 	ra(stack_a, NULL, 1);
//
// 	// TODO: min can rotate the other way around
// }

static void	insert_element(t_stack *stack_a, t_stack *stack_b, const int element)
{
	int	min;
	int	max;

	max = get_max_index(stack_a->list, stack_a->len);
	min = (max + 1) % stack_a->len;


	if (element < stack_a->list[min]) {
		while (min--)
			ra(stack_a, NULL, 1);
	}
	else if (element > stack_a->list[max]) {
		while (min--)
			ra(stack_a, NULL, 1);
	}
	else {
		while (1)
		{
			if (element < stack_a->list[0])
				break ;
			ra(stack_a, stack_b, 1);
		}
	}
	pa(stack_a, stack_b, 1);
}

static void	merge_stacks(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_b->len > 0)
		insert_element(stack_a, stack_b, stack_b->list[0]);
}

void	greedy_algorithm(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_a->len > 3)
	{
		min_movs_rotate(stack_a, stack_b);
		pb(stack_a, stack_b, 1);
	}
	sort3(stack_a);
	merge_stacks(stack_a, stack_b);
	sort_partial_ordered_stack_a(stack_a);
}
