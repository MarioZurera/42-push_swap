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

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	if (stack_a == NULL || stack_b == NULL)
		return ;
	if (stack_a->len == stack_a->size)
		return ;
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
	ft_printf("pa");
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	if (stack_a == NULL || stack_b == NULL)
		return ;
	if (stack_b->len == stack_b->size)
		return ;
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
	ft_printf("pb");
}