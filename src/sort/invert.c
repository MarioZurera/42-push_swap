/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 01:46:01 by mzurera-          #+#    #+#             */
/*   Updated: 2024/08/02 23:42:51 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void sort_4_inverted(t_stack *stack_a, t_stack *stack_b)
{
	sa(stack_a, stack_b, 1);
	ra(stack_a, stack_b, 1);
	ra(stack_a, stack_b, 1);
	sa(stack_a, stack_b, 1);
}

void	sort_inversally_ordered_stack_a(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->len < 4)
	{
		sa(stack_a, stack_b, 1);
		sort_partial_ordered_stack_a(stack_a);
		return ;
	}

	while (stack_a->len > 4)
		pb(stack_a, stack_b, 1);
	sort_4_inverted(stack_a, stack_b);
	while (stack_b->len > 1)
	{
		pa(stack_a, stack_b, 1);
		ra(stack_a, stack_b, 1);
	}
	if (stack_b->len > 0)
		pa(stack_a, stack_b, 1);
	sort_partial_ordered_stack_a(stack_a);
}

int	is_inversally_ordered(const t_stack *stack)
{
	int	i;
	int	curr;
	int	next;
	int	len;

	i = 0;
	len = stack->len;
	while (i < len - 1)
	{
		curr = stack->list[i];
		next = stack->list[i + 1];
		if (curr < next && (curr != 0 || next != len - 1))
				return (0);
		++i;
	}
	return (1);
}
