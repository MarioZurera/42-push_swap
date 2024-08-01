/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 01:27:32 by mzurera-          #+#    #+#             */
/*   Updated: 2024/08/02 01:43:13 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char *argv)
{
    if (argc < 2)
    {
        ft_printf("Usage: %s <list of numbers>", argv[0]);
        exit(1);
    }
    // Parse argv, if argc == 2, then contains spaces. Otherwise is only numbers.
    // Lexer argv and prepare the input for the algorithm
    // Algorithm magic
    return (0);
}

// Considerations: As the program can take as much as 500 elements, I can precache the maximum possible size for each stack.
// Otherwise, 2 stacks of N elements. Being N the amount of number passed as a parameter.