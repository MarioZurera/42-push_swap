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

// 0 1 2 ---
// 2 0 1 --- RA
// 1 2 0 --- RRA
// 1 0 2 --- SWAP
// 0 2 1 --- SWAP + RA
// 2 1 0 --- SWAP + RRA

void	sort3(t_stack *stack) {
	int	*lst;

	lst = stack->list;
	if (stack->len != 3)
		return ;
	if (lst[0] < lst[1] && lst[1] < lst[2])
		return ;
	if (lst[0] > lst[1] && lst[0] > lst[2] && lst[1] < lst[2])
		ra(stack, NULL, 1);
	else if (lst[0] < lst[1] && lst[0] > lst[2] && lst[1] > lst[2])
		rra(stack, NULL, 1);
	else
	{
		sa(stack, NULL, 1);
		sort3(stack);
	}
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
	greedy_algorithm(stack_a, stack_b);
}