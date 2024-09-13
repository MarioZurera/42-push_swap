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



void	sort(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a == NULL || stack_b == NULL)
		return ;
	if (is_partially_ordered(stack_a))
	{
		ft_printf("PARTIAL ORDER!\n");
		sort_partial_ordered_stack_a(stack_a);
		return ;
	}
	ft_printf("NOT PARTIAL ORDER!\n");
	if (is_inversally_ordered(stack_a))
	{
		ft_printf("PARTIAL INV ORDER!\n");
		sort_inversally_ordered_stack_a(stack_a, stack_b);
		return ;
	}
	ft_printf("NOT PARTIAL INV ORDER!\n");
	greedy_algorithm(stack_a, stack_b);
}