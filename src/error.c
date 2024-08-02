/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 18:06:10 by mzurera-          #+#    #+#             */
/*   Updated: 2024/08/02 18:09:12 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_error(void)
{
	ft_printf("Error.\n");
	exit(1);
}

void	check_stack(t_stack *stack)
{
	if (stack == NULL || stack->list == NULL)
		print_error();
}