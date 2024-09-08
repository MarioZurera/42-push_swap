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

t_stack	*tokenize_numbers(int argc, char **argv);
static t_stack	*tokenize_list(t_str_array *list);
static t_str_array *get_list(int argc, char **argv);


t_stack	*tokenize_numbers(int argc, char **argv)
{
	return (tokenize_list(get_list(argc, argv)));
}

static t_stack	*tokenize_list(t_str_array *list)
{
	t_i32_array	*nums;

	nums = list->map(list, ft_strtrim_space)->parse(list);
	list->free(list);
	return (exit_if_null(create_stack(nums->size, nums->list)));
}

static t_str_array *get_list(int argc, char **argv)
{
	if (argc == 2)
		return (exit_if_null(string_array_from(ft_split(argv[1], ' '))));
	return (exit_if_null(string_array_from(argv + 1)));
}
