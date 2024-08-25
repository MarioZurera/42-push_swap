/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 01:27:32 by mzurera-          #+#    #+#             */
/*   Updated: 2024/08/02 23:43:05 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	uint64_t	*stack_a_64;

	stack_a = parse_numbers(tokenize_numbers(argc, argv));
	check_stack(stack_a);
	stack_a_64 = convert_to_9bits_nums(stack_a);
	stack_b = create_stack(stack_a->size, NULL);
	check_stack(stack_b);
	sort(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
