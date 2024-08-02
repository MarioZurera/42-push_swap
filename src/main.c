/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 01:27:32 by mzurera-          #+#    #+#             */
/*   Updated: 2024/08/02 18:26:52 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = parse_numbers(argc, argv);
	check_stack(stack_a);
	stack_b = init_stack(stack_a->size);
	check_stack(stack_b);
	
	// Lexer argv and prepare the input for the algorithm
	// Algorithm magic
	return (0);
}
