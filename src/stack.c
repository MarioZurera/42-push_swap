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

t_stack	*create_stack(unsigned int size, int *nums)
{
	t_stack	*stack;

	if (size == 0)
		return (NULL);
	stack = malloc(sizeof(t_stack));
	if (stack == NULL)
		return (NULL);
	stack->size = size;
	stack->list = nums;
	if (stack->list == NULL)
		stack->list = ft_calloc(size, sizeof(int));
	if (stack->list == NULL)
	{
		free(stack);
		return (NULL);
	}
	return (stack);
}