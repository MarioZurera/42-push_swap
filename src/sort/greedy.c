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

void	check_rotations(int *ra, int *rb, int curr_ra, int curr_rb)
{
	if (*ra == -1 || *rb == -1)
	{
		*ra = curr_ra;
		*rb = curr_rb;
		return ;
	}
}
/*
static void	optimize_rotations(int *curr_ra, int *curr_rb, int len_a, int len_b)
{
	int	rot_a;
	int	rot_b;
	int	cost;

	rot_a = *curr_ra;
	rot_b = *curr_rb;
	cost = ft_max(*curr_ra, *curr_rb);
	if (len_a - *curr_ra + *curr_rb < cost)
	{
		rot_a = *curr_ra - len_a;
		rot_b = *curr_rb;
		cost = -rot_a + rot_b;
	}
	if (*curr_ra + len_b - *curr_rb < cost)
	{
		rot_a = *curr_ra;
		rot_b = *curr_rb - len_b;
		cost = rot_a - rot_b;
	}
	if (ft_max(len_a - *curr_ra, len_b - *curr_rb) < cost)
	{
		rot_a = *curr_ra - len_a;
		rot_b = *curr_rb - len_b;
	}
	*curr_ra = rot_a;
	*curr_rb = rot_b;
}
*/

static void	min_movs_rotate(t_stack *stack_a, t_stack *stack_b)
{
	int	rotations_a;
	// int	rotations_b;
	int	a_curr_rots;
	// int b_curr_rots;

	if (stack_b->size == 0)
		return ;
	rotations_a = -1;
	//rotations_b = -1;
	a_curr_rots = -1;
	while (++a_curr_rots < (int) stack_a->len)
	{
		rotations_a = get_rotations_cost(stack_a, stack_b, a_curr_rots);
		// b_curr_rots = binary_search(stack_b->list, stack_b->len, stack_a->list[a_curr_rots]);
		// optimize_rotations(&a_curr_rots, &b_curr_rots, stack_a->len, stack_b->len);
		// check_rotations(&rotations_a, &rotations_b, a_curr_rots, b_curr_rots);
	}
	rotate(stack_a, stack_b, rotations_a, 1);
}

void	greedy_algorithm(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_a->len > 3)
	{
		min_movs_rotate(stack_a, stack_b);
		pb(stack_a, stack_b, 1);
	}
	sort3(stack_a);
	while (stack_b->len > 0)
	{
		while (stack_a->list[0] < stack_b->list[0])
			rra(stack_a, stack_b, 1);
		pa(stack_a, stack_b, 1);
		if (stack_b->len > 0)
			rra(stack_a, stack_b, 1);
	}
	sort_partial_ordered_stack_a(stack_a);
}

/*static int	calculate_rotations(t_stack *stack_a, t_stack *stack_b, int index)
{
	int	index_a;
	int	index_b;
	int	curr_cost;

	index_a = index;
	index_b = binary_search(stack_b->list, stack_b->len, stack_a->list[index]);
	curr_cost = ft_max(index_a, index_b);
	curr_cost = ft_min(curr_cost, index_a + stack_b->len - index_b);
	curr_cost = ft_min(curr_cost, stack_a->len - index_a + index_b);
	curr_cost = ft_min(curr_cost, ft_max(stack_a->len - index_a, stack_b->len - index_b));
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
	while (i < (int) stack_a->len)
	{
		curr_cost = calculate_rotations(stack_a, stack_b, min_cost, i);
		if (curr_cost >= 0)
		{
			min_cost = curr_cost;
			min_index = i;
		}
		++i;
		ft_printf("%d\t|\t%d\n", min_cost, min_index);
	}
	//rotate(stack_a, stack_b, min_index, 1);
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
	while (s_a_cpy->len > 4)
	{
		cost += find_minimum_cost_and_rotate(s_a_cpy, s_b_cpy);
		pb(s_a_cpy, s_b_cpy, 1);
	}
	return (cost);
}*/