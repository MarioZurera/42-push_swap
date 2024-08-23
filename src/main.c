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
	t_pair	pair;
	t_stack	*stack_b;

	pair->stack_a = parse_numbers(tokenize_numbers(argc, argv));
	check_stack(pair->stack_a);
	pair->stack_b = create_stack(pair->stack_a->size, NULL);
	check_stack(pair->stack_b);
	// Algorithm magic
	free_stack(pair->stack_a);
	free_stack(pair->stack_b);
	return (0);
}
