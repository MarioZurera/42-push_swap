/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 01:24:28 by mzurera-          #+#    #+#             */
/*   Updated: 2024/08/03 20:20:42 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_private.h"

void	push_stack(t_stack *stack, int n)
{
	int	i;

	if (stack->len == stack->size)
		push_swap_error();
	i = stack->len + 1;
	while (--i > 0)
		stack->list[i] = stack->list[i - 1];
	stack->list[0] = n;
	stack->len++;
}

void	push_back_stack(t_stack *stack, int n)
{
	if (stack->len == stack->size)
		push_swap_error();
	stack->list[stack->len++] = n;
}
