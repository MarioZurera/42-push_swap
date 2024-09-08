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
	unsigned int	i;

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
	if (stack == NULL)
		return ;
	free(stack->list);
	free(stack);
}

t_stack	*create_stack_from(t_i32_array *array)
{
	t_stack	*stack;
	stack = create_stack(array->size, array->list);
	array->free(array);
	return (stack);
}

t_stack	*create_stack(const unsigned int size, int *nums)
{
	t_stack	*stack;

	if (size == 0)
		return (NULL);
	stack = smalloc(sizeof(t_stack));
	stack->size = size;
	stack->list = nums;
	stack->len = size;
	if (stack->list == NONE)
	{
		stack->list = scalloc(size, sizeof(int));
		stack->len = 0;
	}
	return (stack);
}

t_stack	*copy_stack(const t_stack *stack)
{
	t_stack	*copy;
	copy = create_stack(stack->size, stack->list);
	if (copy == NULL)
		return (NULL);
	copy->len = stack->len;
	return (copy);
}