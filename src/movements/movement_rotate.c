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
	int				n;
	unsigned int	i;

	(void) stack_b;
	if (stack_a->len < 2)
		return (0);
	n = stack_a->list[0];
	i = 1;
	while (i < stack_a->len)
	{
		stack_a->list[i - 1] = stack_a->list[i];
		++i;
	}
	stack_a->list[i - 1] = n;
	if (print)
		ft_printf("ra\n");
	return (1);
}

int	rb(t_stack *stack_a, t_stack *stack_b, int print)
{
	int				n;
	unsigned int	i;

	(void) stack_a;
	if (stack_b->len < 2)
		return (0);
	n = stack_b->list[0];
	i = 1;
	while (i < stack_b->len)
	{
		stack_b->list[i - 1] = stack_b->list[i];
		++i;
	}
	stack_b->list[i - 1] = n;
	if (print)
		ft_printf("rb\n");
	return (1);
}

int	rr(t_stack *stack_a, t_stack *stack_b, int print)
{
	int				n;
	unsigned int	i;

	if (stack_a->len < 2 || stack_b->len < 2)
		return (0);
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
	if (print)
		ft_printf("rr\n");
	return (1);
}