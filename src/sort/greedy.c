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
/*
// static int	is_anti_ordered(const t_stack *stack)
// {
// 	unsigned int	i;
//
// 	i = 0;
// 	while (i < stack->len - 1 && stack->list[i] > stack->list[i + 1])
// 		++i;
// 	return (i == stack->len - 1);
// }

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
*/
int	get_max_index(int *arr, int size)
{
	int	i;
	int	max;
	int	max_i;

	i = -1;
	max_i = 0;
	max = INT_MAX;
	while (++i < size) {
		if (arr[i] > max)
		{
			max = arr[i];
			max_i = i;
		}
	}
	return (max_i);
}
/*
// static int	get_min_index(int *arr, int size)
// {
// 	int	i;
// 	int	min;
// 	int	min_i;
//
// 	i = -1;
// 	min_i = 0;
// 	min = INT_MAX;
// 	while (++i < size) {
// 		if (arr[i] < min)
// 		{
// 			min = arr[i];
// 			min_i = i;
// 		}
// 	}
// 	return (min_i);
// }

static void	rotate_b(t_stack *stack_b, int index)
{
	if (index > (int) stack_b->len / 2)
	{
		index = stack_b->len - index;
		while (index--)
			rrb(stack_b, NULL, 1);
	}
	else
	{
		while (index--)
			rb(stack_b, NULL, 1);
	}

	// TODO: min can rotate the other way around
}
*/


// static int	get_max_element(int *arr, int size)
// {
// 	int	i;
// 	int	max;
//
// 	i = -1;
// 	max = INT_MIN;
// 	while (++i < size) {
// 		if (arr[i] > max)
// 			max = arr[i];
// 	}
// 	return (max);
// }
/*
static int	get_supreme_index(int *arr, int size, int element)
{
	int	i;
	int	supreme_i;
	int	supreme;

	if (element > get_max_element(arr, size))
		return (get_min_index(arr, size));
	i = -1;
	supreme_i = -1;
	supreme = INT_MAX;
	while (++i < size) {
		if (arr[i] < supreme && arr[i] > element)
		{
			supreme = arr[i];
			supreme_i = i;
		}
	}
	if (supreme_i == -1)
		return (get_min_index(arr, size));
	return (supreme_i);
}


static void	insert_element(t_stack *stack_a, t_stack *stack_b, const int element)
{
	int	supreme_i;

	supreme_i = get_supreme_index(stack_a->list, stack_a->len, element);
	// ft_printf("%d\n", supreme_i);
	rotate_a(stack_a, supreme_i);
	pa(stack_a, stack_b, 1);
}
*/

/*
static void	merge_stacks(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_b->len > 0 && stack_b->list[0] > stack_a->list[stack_a->len - 1])
		pa(stack_a, stack_b, 1);
	rra(stack_a, stack_b, 1);
	while (stack_b->len > 0 && stack_b->list[0] > stack_a->list[stack_a->len - 1])
		pa(stack_a, stack_b, 1);
	rra(stack_a, stack_b, 1);
	while (stack_b->len > 0 && stack_b->list[0] > stack_a->list[stack_a->len - 1])
		pa(stack_a, stack_b, 1);
	rra(stack_a, stack_b, 1);
	while (stack_b->len > 0)
		pa(stack_a, stack_b, 1);
}
*/

static void print_stack(const t_stack *stack)
{
	// (void)stack;
	// ft_printf("Ordered: %d\n", is_anti_ordered(stack));
	for (int i = 0; i < (int) stack->len; i++)
		ft_printf("%d\n", stack->list[i]);
}

void	greedy_algorithm(t_stack *stack_a, t_stack *stack_b)
{
	// while (stack_a->len > 3)
	// {
	// 	min_movs_rotate(stack_a, stack_b);
	// 	pb(stack_a, stack_b, 1);
	// 	// if (get_min_index(stack_b->list, stack_b->len) == 0)
	// 	// 	sb(stack_a, stack_b, 1);
	// 	print_stack(stack_b);
	// 	ft_printf("------------------------------------------------\n");
	// }
	// sort3(stack_a);
	// rotate_b(stack_b, get_max_index(stack_b->list, stack_b->len));
	// merge_stacks(stack_a, stack_b);
	// sort_partial_ordered_stack_a(stack_a);

	print_stack(stack_b);
	ft_printf("------------------------------------------------\n");

	ra(stack_a, stack_b, 1);
	print_stack(stack_a);
	pb(stack_a, stack_b, 1);
	pb(stack_a, stack_b, 1);
	pb(stack_a, stack_b, 1);
	print_stack(stack_a);
	rb(stack_a, stack_b, 1);
	print_stack(stack_b);

}
