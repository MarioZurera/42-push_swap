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
	int				n;
	unsigned int	i;

	(void) stack_b;
	if (stack_a->len < 2)
		return (0);
	i = stack_a->len - 1;
	n = stack_a->list[i];
	while (i > 0)
	{
		stack_a->list[i] = stack_a->list[i - 1];
		--i;
	}
	stack_a->list[i] = n;
	if (print)
		ft_printf("rra\n");
	return (1);
}

int	rrb(t_stack *stack_a, t_stack *stack_b, int print)
{
	int				n;
	unsigned int	i;

	(void) stack_a;
	if (stack_b->len < 2)
		return (0);
	i = stack_b->len - 1;
	n = stack_b->list[i];
	while (i > 0)
	{
		stack_b->list[i] = stack_b->list[i - 1];
		--i;
	}
	stack_b->list[i] = n;
	if (print)
		ft_printf("rrb\n");
	return (1);
}

int	rrr(t_stack *stack_a, t_stack *stack_b, int print)
{
	int				n;
	unsigned int	i;

	if (stack_a->len < 2 || stack_b->len < 2)
		return (0);
	i = stack_a->len - 1;
	n = stack_a->list[i];
	while (i > 0)
	{
		stack_a->list[i] = stack_a->list[i - 1];
		--i;
	}
	stack_a->list[i] = n;
	n = stack_b->list[stack_b->len - 1];
	i = stack_b->len - 1;
	while (i > 0)
	{
		stack_b->list[i] = stack_b->list[i - 1];
		--i;
	}
	stack_b->list[i] = n;
	if (print)
		ft_printf("rrr\n");
	return (1);
}