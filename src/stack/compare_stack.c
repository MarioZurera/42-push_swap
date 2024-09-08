/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 01:24:28 by mzurera-          #+#    #+#             */
/*   Updated: 2024/08/03 20:20:42 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_private.h"

int	compare_stacks(const t_stack *stack_a, const t_stack *stack_b)
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