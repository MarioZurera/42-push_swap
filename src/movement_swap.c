/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 15:33:07 by mzurera-          #+#    #+#             */
/*   Updated: 2024/08/24 22:41:15 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	sa(t_stack *stack_a, t_stack *stack_b)
{
	(void) stack_b;
	if (stack_a == NULL || stack_a->list == NULL)
		return ;
	swap(stack_a->list, stack_a->list + 1);
	ft_printf("sa");
}

void	sb(t_stack *stack_a, t_stack *stack_b)
{
	(void) stack_a;
	if (stack_b == NULL || stack_b->list == NULL)
		return ;
	swap(stack_b->list, stack_b->list + 1);
	ft_printf("sb");
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a == NULL || stack_b == NULL
		|| stack_a->list == NULL || stack_b->list == NULL)
		return ;
	swap(stack_a->list, stack_a->list + 1);
	swap(stack_b->list, stack_b->list + 1);
	ft_printf("ss");
}