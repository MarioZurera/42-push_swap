/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 15:33:07 by mzurera-          #+#    #+#             */
/*   Updated: 2024/08/24 22:41:15 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pa(t_stack *stack_a, t_stack *stack_b, int print)
{
	if (stack_b->is_empty(stack_b))
		return (0);
	stack_a->push(stack_a, stack_b->pop(stack_b));
	if (print != 0)
		ft_printf("pa\n");
	return (1);
}

int	pb(t_stack *stack_a, t_stack *stack_b, int print)
{
	if (stack_a->is_empty(stack_a))
		return (0);
	stack_b->push(stack_b, stack_a->pop(stack_a));
	if (print != 0)
		ft_printf("pb\n");
	return (1);
}