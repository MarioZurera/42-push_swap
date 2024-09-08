/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 01:24:28 by mzurera-          #+#    #+#             */
/*   Updated: 2024/08/03 20:20:42 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_private.h"

int	pop_stack(t_stack *stack)
{
	int	n;
	int	i;

	if (stack->len == 0)
		push_swap_error();
	n = stack->list[0];
	i = 0;
	while (++i < (int) stack->len)
		stack->list[i - 1] = stack->list[i];
	stack->len--;
	return (n);
}

int	pop_back_stack(t_stack *stack)
{
	if (stack->len == 0)
		return (-1);
	return (stack->list[--stack->len]);
}
