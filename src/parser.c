/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 01:46:01 by mzurera-          #+#    #+#             */
/*   Updated: 2024/08/02 03:27:30 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int is_correct_format_number(char *num)
{
	unsigned int	i;
	
	if (!ft_isdigit(num[0]) && num[0] != '-' && num[0] != '+')
		return (0);
	i = 1;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	add_number(t_stack stack, int index, char *str_num)
{
	int	num;
	
	if (!is_correct_format_number(stack, str_num))
	{
		free(stack);
		return (0);
	}
	num = ft_atol(str_num);
	if (num < INT_MIN || num > INT_MAX)
	{
		free_stack(stack);
		return (0);
	}
	stack.list[index] = num;
	return (1);
}

static t_stack	parse_string(char *str)
{
	int		i;
	int		j;
	int		index;
	t_stack	*stack;

	init_stack(ft_count_words(str));
	j = 0;
	index = 0;
	while (str[j])
	{
		while (str[j] && str[j] == ' ')
			j++;
		i = j;
		while (str[j] && str[j] != ' ')
			j++;
		str[j++] = '\0';
		if (str[j - 1] == '\0')
		{
			if (add_number(stack, index, str + i) == 0)
				return (NULL);
			index++;
		}
	}
	return (stack);
}

static t_stack	parse_list(int argc, char **argv)
{
	int		i;
	int		index;
	t_stack	stack;

	stack = init_stack(argc - 1);
	i = 0;
	index = 0;
	while (i < argc - 1)
	{
		if (add_number(stack, index, argv[i]) == 0)
			return (NULL);
		index++;
		i++;
	}
	return (stack);
}

t_stack	parse_numbers(int argc, char **argv)
{
	if (argc < 2)
		return (NULL);
	if (argc == 2)
		return (parse_string(argv[1]));
	if (argc > 2)
		return (parse_list(argc, argv));
}