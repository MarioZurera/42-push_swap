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
	int	tmp_cost;

	rotations_b = 0;
	b_curr_rots = -1;
	cost = INT_MAX;
	while (++b_curr_rots < (int) stack_b->len)
	{
		tmp_cost = get_rotations_cost(stack_a, stack_b, b_curr_rots);
		if (tmp_cost < cost)
		{
			rotations_b = b_curr_rots;
			cost = tmp_cost;
		}
	}
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
	while (++i < size)
	{
		if (arr[i] < min)
		{
			min = arr[i];
			min_i = i;
		}
	}
	return (min_i);
}

static int	get_subarray(const int *arr, int n, int *end)
{
	int	max_length;
	int	current_length;
	int	tmp_end;
	int	i;

	i = 0;
	max_length = 1;
	current_length = 1;
	if (n == 0)
		return (0);
	while (i < 2 * n - 1)
	{
		if (arr[(i + 1) % n] > arr[i % n])
		{
			current_length++;
			tmp_end = (i + 1) % n;
		}
		else
			set_sublen(&current_length, &max_length, end, tmp_end);
		i++;
	}
	set_sublen(&current_length, &max_length, end, tmp_end);
	return (max_length);
}

void	push_to_b(t_stack *stack_a, t_stack *stack_b)
{
	int	length;
	int	start;
	int	end;
	int	*list;
	int	len;

	list = stack_a->list;
	len = (int) stack_a->len;
	length = get_subarray(list, len, &end);
	start = (len + end - (length - 1)) % len;
	if (end - start < 0 || start == 0)
	{
		rotate_a(stack_a, end + 1);
		start = len - length;
	}
	while (start > 0)
	{
		start--;
		pb(stack_a, stack_b, 1);
	}
	if (len == length)
		return ;
	rotate_a(stack_a, length);
	while ((int) stack_a->len > length)
		pb(stack_a, stack_b, 1);
}

void	greedy_algorithm(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->len <= 5)
		push_to_b_tiny(stack_a, stack_b);
	else
		push_to_b(stack_a, stack_b);
	while (stack_b->len > 0)
	{
		min_movs_rotate(stack_a, stack_b);
		pa(stack_a, stack_b, 1);
	}
	rotate_a(stack_a, get_min_index(stack_a->list, stack_a->len));
}
