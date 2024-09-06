/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 01:46:01 by mzurera-          #+#    #+#             */
/*   Updated: 2024/08/02 23:42:51 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort3(t_stack *stack_a, t_stack *stack_b)
{
	sa(stack_a, stack_b, 1);
	if (!is_ordered(stack_a))
		sort_partial_ordered_stack_a(stack_a);
}

void	sort(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a == NULL || stack_b == NULL)
		return ;
	if (is_partially_ordered(stack_a))
	{
		sort_partial_ordered_stack_a(stack_a);
		return ;
	}
	if (is_inversally_ordered(stack_a))
	{
		sort_inversally_ordered_stack_a(stack_a, stack_b);
		return ;
	}
	if (stack_a->len <= 3)
		sort3(stack_a, stack_b);
	greedy_algorithm(stack_a, stack_b);
	//if (stack_a->len <= 5)
	//	sort_5(stack_a, stack_b);
}