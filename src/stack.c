/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 01:46:01 by mzurera-          #+#    #+#             */
/*   Updated: 2024/08/02 23:42:51 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	compare_stacks(t_stack *stackA, t_stack *stackB)
{
	int	i;

	if (!stackA || !stackB)
		return (0);
	if (stackA->size != stackB->size)
		return (0);
	i = 0;
	while (i < stackA->size && stackA->list[i] == stackB->list[i])
		i++;
	return (i == stackA->size);
}

void	free_stack(t_stack *stack)
{
	free(stack->list);
	free(stack);
}

t_stack	*create_stack(unsigned int size)
{
	t_stack	*stack;

	if (size == 0)
		return (NULL);
	stack = malloc(sizeof(t_stack));
	if (stack == NULL)
		return (NULL);
	stack->size = size;
	stack->list = malloc(size * sizeof(int));
	return (stack);
}

t_stack	*create_stack(unsigned int size, int *nums)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));

	stack->size = size;
	stack->list = nums;

	return (stack);
}