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
	int	i;

	if (stack_a == NULL || stack_b == NULL)
		return (0);
	if (stack_a->len == stack_a->size || stack_b->len == 0)
		return (0);
	i = stack_a->len - 1;
	while (i >= 0)
	{
		stack_a->list[i + 1] = stack_a->list[i];
		--i;
	}
	stack_a->list[0] = stack_b->list[0];
	i = 1;
	while ((unsigned int) i < stack_b->len)
	{
		stack_b->list[i - 1] = stack_b->list[i];
		++i;
	}
	++stack_a->len;
	--stack_b->len;
	if (print)
		ft_printf("pa\n");
	return (1);
}

int	pb(t_stack *stack_a, t_stack *stack_b, int print)
{
	int	i;

	if (stack_a == NULL || stack_b == NULL)
		return (0);
	if (stack_b->len == stack_b->size || stack_a->len == 0)
		return (0);
	i = stack_b->len - 1;
	while (i >= 0)
	{
		stack_b->list[i + 1] = stack_b->list[i];
		--i;
	}
	stack_b->list[0] = stack_a->list[0];
	i = 1;
	while ((unsigned int) i < stack_a->len)
	{
		stack_a->list[i - 1] = stack_a->list[i];
		++i;
	}
	--stack_a->len;
	++stack_b->len;
	if (print)
		ft_printf("pb\n");
	return (1);
}