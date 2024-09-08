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

#include "../../includes/push_swap.h"

static void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	sa(t_stack *stack_a, t_stack *stack_b, int print)
{
	(void) stack_b;
	if (stack_a->len < 2)
		return (0);
	swap(stack_a->list, stack_a->list + 1);
	if (print != 0)
		ft_printf("sa\n");
	return (1);
}

int	sb(t_stack *stack_a, t_stack *stack_b, int print)
{
	(void) stack_a;
	if (stack_b->len < 2)
		return (0);
	swap(stack_b->list, stack_b->list + 1);
	if (print != 0)
		ft_printf("sb\n");
	return (1);
}

int	ss(t_stack *stack_a, t_stack *stack_b, int print)
{
	if (stack_a->len < 2 || stack_b->len < 2)
		return (0);
	swap(stack_a->list, stack_a->list + 1);
	swap(stack_b->list, stack_b->list + 1);
	if (print != 0)
		ft_printf("ss\n");
	return (1);
}
