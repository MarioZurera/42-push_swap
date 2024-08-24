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

#include "push_swap.h"

void	rra(t_stack *stack_a, t_stack *stack_b)
{
	int				n;
	unsigned int	i;

	(void) stack_b;
	n = stack_a->list[stack_a->len - 1];
	i = stack_a->len - 1;
	while (i > 0)
	{
		stack_a->list[i - 1] = stack_a->list[i];
		--i;
	}
	stack_a->list[i + 1] = n;
	ft_printf("rra\n");
}

void	rrb(t_stack *stack_a, t_stack *stack_b)
{
	int				n;
	unsigned int	i;

	(void) stack_a;
	n = stack_b->list[stack_b->len - 1];
	i = stack_b->len - 1;
	while (i > 0)
	{
		stack_b->list[i - 1] = stack_b->list[i];
		--i;
	}
	stack_b->list[i + 1] = n;
	ft_printf("rrb\n");
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	int				n;
	unsigned int	i;

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
	ft_printf("rrr\n");
}