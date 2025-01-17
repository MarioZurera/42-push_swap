/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 15:33:07 by mzurera-          #+#    #+#             */
/*   Updated: 2024/08/24 22:41:15 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ra(t_stack *stack_a, t_stack *stack_b, int print)
{
	(void) stack_b;
	if (stack_a->len < 2)
		return (0);
	stack_a->push_back(stack_a, stack_a->pop(stack_a));
	if (print != 0)
		ft_printf("ra\n");
	return (1);
}

int	rb(t_stack *stack_a, t_stack *stack_b, int print)
{
	(void) stack_a;
	if (stack_b->len < 2)
		return (0);
	stack_b->push_back(stack_b, stack_b->pop(stack_b));
	if (print != 0)
		ft_printf("rb\n");
	return (1);
}

int	rr(t_stack *stack_a, t_stack *stack_b, int print)
{
	if (stack_a->len < 2 && stack_b->len < 2)
		return (0);
	ra(stack_a, stack_b, 0);
	rb(stack_a, stack_b, 0);
	if (print != 0)
		ft_printf("rr\n");
	return (1);
}
