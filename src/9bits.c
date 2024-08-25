/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   9bits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 18:06:10 by mzurera-          #+#    #+#             */
/*   Updated: 2024/08/03 14:37:27 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

uint64_t	create_64int_num(t_stack *stack, unsigned int i)
{
	uint64_t		num;
	unsigned int	j;

	num = 0;
	j = 0;
	while (j < 7 && i + j < stack->len)
	{
		stack->list[i + j]
	}
}

uint64_t	*convert_to_9bits_nums(t_stack *stack)
{
	uint64_t		*nums;
	unsigned int	i;
	unsigned int	nums_per_64bits;

	nums_per_64bits = sizeof(uint64_t) / 9;
	nums = ft_calloc((stack->size / nums_per_64bits) + 2, sizeof(uint64_t));
	if (nums == NULL)
		return (NULL);
	i = 0;
	while (i < stack->len)
	{
		nums[i] = create_64int_num(stack, i * 7);
		++i;
	}
	return (nums);
}