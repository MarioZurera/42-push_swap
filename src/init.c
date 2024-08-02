/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 03:25:00 by mzurera-          #+#    #+#             */
/*   Updated: 2024/08/02 03:26:41 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	init_stack(int amount_of_nums)
{
	t_stack			*stack;


	stack = malloc(sizeof(t_stack));
	if (stack == NULL)
		return (NULL);
	stack->size = amount_of_nums;
	stack->list = malloc(amount_of_nums * sizeof(int));
}

void	free_stack(t_stack stack)
{
	free(stack.list);
	free(stack);
}