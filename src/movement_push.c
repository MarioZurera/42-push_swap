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

static int	copy_list(int src[], int *dest[], unsigned int size)
{
	unsigned int	i;

	if (src == NULL || size == 0)
		return (0);
	*dest = malloc(sizeof(int) * size);
	if (*dest == NULL)
		return (0);
	i = 0;
	while (i < size)
	{
		(*dest)[i] = src[i];
		i++;
	}
	return (1);
}

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	unsigned int	i;

	if (stack_a == NULL || stack_b == NULL)
		return ;
	if (stack_a->len == stack_a->size)
		return ;
	i = stack_a->len;
	while (i > 0)
	{
		stack_a->list[i + 1] = stack_a->list[i];
		--i;
	}
	stack_a->list[0] = stack_b->list[0];
	i = 1;
	while (i < stack_b->len )
	{
		stack_b->list[i - 1] = stack_b->list[i];
		++i;
	}
	--stack_a->len;
	++stack_b->len;
	ft_printf("pa");
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	unsigned int	i;

	if (stack_a == NULL || stack_b == NULL)
		return ;
	if (stack_b->len == stack_b->size)
		return ;
	i = stack_b->len;
	while (i > 0)
	{
		stack_b->list[i + 1] = stack_b->list[i];
		--i;
	}
	stack_b->list[0] = stack_a->list[0];
	i = 1;
	while (i < stack_a->len )
	{
		stack_a->list[i - 1] = stack_a->list[i];
		++i;
	}
	++stack_a->len;
	--stack_b->len;
	ft_printf("pb");
}