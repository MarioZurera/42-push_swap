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

t_stack	*create_stack(const unsigned int size, int *nums);

static void	free_stack(t_stack *stack)
{
	free(stack->list);
	free(stack);
}

static t_stack	*copy_stack(const t_stack *stack)
{
	t_stack	*copy;
	copy = create_stack(stack->size, stack->list);
	copy->len = stack->len;
	return (copy);
}

static int	compare_stacks(t_stack *stack_a, t_stack *stack_b)
{
	unsigned int	i;

	if (!stack_a || !stack_b)
		return (0);
	if (stack_a->size != stack_b->size)
		return (0);
	i = 0;
	while (i < stack_a->size && stack_a->list[i] == stack_b->list[i])
		i++;
	return (i == stack_a->size);
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
		push_swap_error();
	stack = smalloc(sizeof(t_stack));
	stack->size = size;
	stack->list = nums;
	stack->len = size;
	if (stack->list == NONE)
	{
		stack->list = scalloc(size, sizeof(int));
		stack->len = 0;
	}
	stack->free = &free_stack;
	stack->copy = &copy_stack;
	stack->cmp = &compare_stacks;
	return (stack);
}