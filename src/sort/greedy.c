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
	cost = INT_MAX;
	while (++b_curr_rots < (int) stack_b->len)
	{
		tmp_cost = get_rotations_cost(stack_a, stack_b, b_curr_rots);
		// ft_printf("Current cost is: %d\n", tmp_cost);
		if (tmp_cost < cost)
		{
			rotations_b = b_curr_rots;
			cost = tmp_cost;
		}
	}
	// ft_printf("Rotations B: %i", rotations_b);
	rotate(stack_a, stack_b, rotations_b, 1);
}

int	get_min_index(int *arr, int size)
{
	int	i;
	int	min;
	int	min_i;

	i = -1;
	min_i = 0;
	min = INT_MAX;
	while (++i < size) {
		if (arr[i] < min)
		{
			min = arr[i];
			min_i = i;
		}
	}
	return (min_i);
}


void print_stack(t_stack *stack) {
	for (unsigned i = 0; i < stack->len; i++) {
		ft_printf("%d | ", stack->list[i]);
	}
	ft_printf("(LEN: %d)\n", stack->len);
}

// static unsigned int	get_subarray(const int *arr, int n, int *end) {
// 	int	max_length;
// 	int	current_length;
// 	int	tmp_end;
// 	int	i;
//
// 	i = 0;
// 	max_length = 1;
// 	current_length = 1;
// 	if (n == 0)
// 		return 0;
// 	while (i < 2 * n - 1)
// 	{
// 		if (arr[(i + 1) % n] > arr[i % n]) {
// 			current_length++;
// 			tmp_end = (i + 1) % n;
// 		}
// 		else
// 		{
// 			if (current_length > max_length) {
// 				max_length = current_length;
// 				*end = tmp_end;
// 			}
// 			current_length = 1;
// 		}
// 		i++;
// 	}
// 	if (current_length > max_length) {
// 		max_length = current_length;
// 		*end = tmp_end;
// 	}
// 	*end = (*end + 1) % n;
// 	return max_length;
// }

void	greedy_algorithm(t_stack *stack_a, t_stack *stack_b)
{
	// unsigned int				sub_length;
	// int				end_subarray;
	// int				*list;
	// unsigned int	len;
	//
	// list = stack_a->list;
	// len = stack_a->len;
	// // Find longest already sorted segment in A (avoid pushing into B)
	// if (len > 20)
	// {
	// 	sub_length = get_subarray(list, len, &end_subarray);
	// 	rotate_movements(stack_a, stack_b, (int[]){ end_subarray, 0} , 1);
	// }
	// else
	// 	sub_length = 3;
	while (stack_a->len > 3)
		pb(stack_a, stack_b, 1);
	sort3(stack_a);
	while (stack_b->len > 0)
	{
		min_movs_rotate(stack_a, stack_b);
		pa(stack_a, stack_b, 1);
	}
	rotate_movements(stack_a, stack_b, (int[]){ get_min_index(stack_a->list, stack_a->len), 0} , 1);
}
