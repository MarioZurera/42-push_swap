/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 18:06:10 by mzurera-          #+#    #+#             */
/*   Updated: 2024/08/03 14:37:27 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_error(void) {
	write(STDERR_FILENO, "Error\n", 6);
}

int	check_stack(t_stack *stack) {
	if (stack == NULL || stack->list == NULL)
	{
		print_error();
		return (0);
	}
	return (1);
}

void	*exit_if_null(void *ptr)
{
	if (ptr == NULL)
		print_error();
	return (ptr);
}