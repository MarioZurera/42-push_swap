/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 01:46:01 by mzurera-          #+#    #+#             */
/*   Updated: 2024/08/02 23:42:51 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stack_private.h"

t_stack	*create_stack_from(t_i32_array *array)
{
	t_stack	*stack;

	if (array == NULL)
		push_swap_error();
	if (array->size == 0)
	{
		array->free(array);
		push_swap_error();
	}
	stack = create_stack(array->size, array->list);
	free(array);
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
	if (stack->list == NULL)
	{
		stack->list = scalloc(size, sizeof(int));
		stack->len = 0;
	}
	stack->free = &free_stack;
	stack->copy = &copy_stack;
	stack->cmp = &compare_stacks;
	stack->push = &push_stack;
	stack->push_back = &push_back_stack;
	stack->pop = &pop_stack;
	stack->pop_back = &pop_back_stack;
	stack->is_empty = &is_empty_stack;
	stack->is_full = &is_full_stack;
	return (stack);
}
