/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_reverse.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 15:33:07 by mzurera-          #+#    #+#             */
/*   Updated: 2024/08/24 22:41:15 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	rra(t_stack *stack_a, t_stack *stack_b, int print)
{
	(void) stack_b;
	if (stack_a->len < 2)
		return (0);
	stack_a->push(stack_a, stack_a->pop_back(stack_a));
	if (print != 0)
		ft_printf("rra\n");
	return (1);
}

int	rrb(t_stack *stack_a, t_stack *stack_b, int print)
{
	(void) stack_a;
	stack_b->push(stack_b, stack_b->pop_back(stack_b));
	if (print != 0)
		ft_printf("rrb\n");
	return (1);
}

int	rrr(t_stack *stack_a, t_stack *stack_b, int print)
{
	if (stack_a->len < 2 || stack_b->len < 2)
		return (0);
	rra(stack_a, stack_b, 0);
	rrb(stack_a, stack_b, 0);
	if (print != 0)
		ft_printf("rrr\n");
	return (1);
}
