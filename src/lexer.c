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

static int	add_number(t_stack *stack, int index, char *str_num)
{
	long	num;
	
	if (!is_correct_format_number(str_num))
	{
		free_stack(stack);
		return (0);
	}
	num = ft_atol(str_num);
	if (num < INT_MIN || num > INT_MAX)
	{
		free_stack(stack);
		return (0);
	}
	stack->list[index] = num;
	return (1);
}

static t_stack	*tokenize_string(char *str)
{
	int		i;
	int		j;
	int		index;
	t_stack	*stack;

	stack = create_stack(ft_count_words(str), NULL);
	j = 0;
	index = 0;
	while (str[j] && stack != NULL)
	{
		while (str[j] && ft_isspace(str[j]))
			j++;
		i = j;
		while (str[j] && !ft_isspace(str[j]))
			j++;
		if (str[j] != '\0')
			str[j++] = '\0';
		if (i != j && add_number(stack, index, str + i) == 0)
			return (NULL);
		index++;
	}
	return (stack);
}

static t_stack	*tokenize_list(int argc, char **argv)
{
	int		i;
	int		index;
	char	*str;
	t_stack	*stack;

	stack = create_stack(argc - 1, NULL);
	i = 1;
	index = 0;
	while (i < argc)
	{
		str = ft_strtrim(argv[i], " \n\r\v\f\t");
		if (add_number(stack, index, str) == 0)
		{
			free(str);
			return (NULL);
		}
		free(str);
		index++;
		i++;
	}
	return (stack);
}

t_stack	*tokenize_numbers(int argc, char **argv)
{
	char	*str;
	t_stack	*stack;

	stack = NULL;
	if (argc == 2)
	{
		str = ft_strdup(argv[1]);
		if (str == NULL)
			return (NULL);
		stack = tokenize_string(str);
		free(str);
	}
	if (argc > 2)
		stack = tokenize_list(argc, argv);
	return (stack);
}
