/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ordered.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 01:46:01 by mzurera-          #+#    #+#             */
/*   Updated: 2024/08/02 23:42:51 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	is_ordered(const t_stack *stack)
{
	unsigned int	i;

	i = 0;
	while (i < stack->len && stack->list[i] == (int) i)
		++i;
	return (i == stack->len);
}

int	is_ordered_from(const t_stack *stack)
{
	unsigned int	i;

	i = 0;
	while (i < stack->len - 1 && stack->list[i] < stack->list[i + 1])
		++i;
	return (i == stack->len - 1);
}

int	is_partially_ordered(const t_stack *stack) {
	unsigned int	i;
	unsigned int	n;

	i = 0;
	n = stack->list[0];
	while (i < stack->len && stack->list[i] == (int) ((n + i) % stack->len))
		++i;
	return (i == stack->len);
}

static int	rotations_to_order(const t_stack *stack)
{
	unsigned int	i;

	i = 0;
	while (i < stack->len - 1)
	{
		if (stack->list[i] > stack->list[i + 1])
			return (i + 1);
		++i;
	}
	return (0);
}

void	sort_partial_ordered_stack_a(t_stack *stack_a)
{
	int	n;
	int	i;

	i = 0;
	n = rotations_to_order(stack_a);
	if (n <= ((int) stack_a->len) - n)
	{
		while (i < n)
		{
			ra(stack_a, NULL, 1);
			++i;
		}
	}
	else
	{
		while (i < ((int) stack_a->len) - n)
		{
			rra(stack_a, NULL, 1);
			++i;
		}
	}
}