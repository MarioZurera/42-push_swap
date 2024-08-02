/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 01:27:32 by mzurera-          #+#    #+#             */
/*   Updated: 2024/08/02 03:28:13 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		ft_printf("Error\n");
		exit(1);
	}
	parse_numbers(argc, argv);
	// Lexer argv and prepare the input for the algorithm
	// Algorithm magic
	return (0);
}

// Considerations: As the program can take as much as 500 elements, I can precache the maximum possible size for each stack.
// Otherwise, 2 stacks of N elements. Being N the amount of number passed as a parameter.