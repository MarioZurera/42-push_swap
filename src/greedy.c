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

static int	calculate_rotations(t_stack *stack_a, t_stack *stack_b,
	int min_cost, int index)
{
	int	index_a;
	int	index_b;
	int	curr_cost;

	curr_cost = -1;
	index_a = index;
	index_b = binary_search(stack_b->list, stack_b->len, stack_a->list[index]);
	if (index_b < 0)
		return (index_b);
	if ((index_a > min_cost || index_b > min_cost) && min_cost >= 0)
		return (-1);
	curr_cost = ft_max(index_a, index_b);
	curr_cost = ft_min(curr_cost, index_a + stack_b->len - index_b);
	curr_cost = ft_min(curr_cost, stack_a->len - index_a + index_b);
	curr_cost = ft_min(curr_cost, ft_max(stack_a->len - index_a, stack_b->len - index_b));
	if (curr_cost >= min_cost && min_cost >= 0)
		return (-1);
	return (curr_cost);
}

static int	find_minimum_cost_and_rotate(t_stack *stack_a, t_stack *stack_b)
{
	int		i;
	int		curr_cost;
	int		min_cost;
	int		min_index;

	i = 0;
	min_cost = -1;
	min_index = -1;
	while ((unsigned int) i < stack_a->len)
	{
		curr_cost = calculate_rotations(stack_a, stack_b, min_cost, i);
		if (curr_cost < 0)
			continue ;
		min_cost = curr_cost;
		min_index = i;
		++i;
	}
	rotate(stack_a, stack_b, min_index, 0);
	return (min_cost);
}

int	greedy_algorithm(const t_stack *stack_a, const t_stack *stack_b)
{
	t_stack	*s_a_cpy;
	t_stack	*s_b_cpy;
	int		cost;

	s_a_cpy = stack_a->copy(stack_a);
	s_b_cpy = stack_b->copy(stack_b);
	cost = 0;
	while (stack_a->len > 4)
	{
		cost += find_minimum_cost_and_rotate(s_a_cpy, s_b_cpy);
		pb(s_a_cpy, s_b_cpy, 0);
	}
	return (cost);
}