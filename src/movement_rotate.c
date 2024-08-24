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

#include "push_swap.h"

void	ra(t_stack *stack_a, t_stack *stack_b)
{
	int				n;
	unsigned int	i;

	(void) stack_b;
	n = stack_a->list[0];
	i = 1;
	while (i < stack_a->len)
	{
		stack_a->list[i - 1] = stack_a->list[i];
		++i;
	}
	stack_a->list[i - 1] = n;
	ft_printf("ra");
}

void	rb(t_stack *stack_a, t_stack *stack_b)
{
	int				n;
	unsigned int	i;

	(void) stack_a;
	n = stack_b->list[0];
	i = 1;
	while (i < stack_b->len)
	{
		stack_b->list[i - 1] = stack_b->list[i];
		++i;
	}
	stack_b->list[i - 1] = n;
	ft_printf("rb");
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	int				n;
	unsigned int	i;

	n = stack_a->list[0];
	i = 1;
	while (i < stack_a->len)
	{
		stack_a->list[i - 1] = stack_a->list[i];
		++i;
	}
	stack_a->list[i - 1] = n;
	n = stack_b->list[0];
	i = 1;
	while (i < stack_b->len)
	{
		stack_b->list[i - 1] = stack_b->list[i];
		++i;
	}
	stack_b->list[i - 1] = n;
	ft_printf("rr");
}