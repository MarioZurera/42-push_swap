/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 18:06:10 by mzurera-          #+#    #+#             */
/*   Updated: 2024/08/03 14:37:27 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	set_sublen(int *current_length, int *max_length, int *end, int tmp_end)
{
	if (*current_length > *max_length)
	{
		*max_length = *current_length;
		*end = tmp_end;
	}
	*current_length = 1;
}

void	push_to_b_tiny(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_a->len > 3)
		pb(stack_a, stack_b, 1);
	sort3(stack_a);
}
