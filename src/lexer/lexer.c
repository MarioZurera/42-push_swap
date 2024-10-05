/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 01:46:01 by mzurera-          #+#    #+#             */
/*   Updated: 2024/08/02 23:42:51 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_stack(t_stack *stack) {
	for (unsigned i = 0; i < stack->len; i++) {
		ft_printf("%d | ", stack->list[i]);
	}
	ft_printf("(LEN: %d)\n", stack->len);
}

static t_str_array	*get_list(int argc, char **argv)
{
	if (argc == 2)
		return (string_array_from(ft_split(argv[1], ' ')));
	return (string_array_from_const(argv + 1));
}

static t_stack	*tokenize_list(t_str_array *list)
{
	return (create_stack_from(list->map(list, &ft_strtrim_space)->parse(list)));
}

t_stack	*tokenize_numbers(int argc, char **argv)
{

	return (tokenize_list(get_list(argc, argv)));
}
