/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_string_array.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 01:46:01 by mzurera-          #+#    #+#             */
/*   Updated: 2024/08/02 23:42:51 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_array_private.h"

static int	ft_isdigit(const int c)
{
	return ('0' <= c && c <= '9');
}

static int	ft_isspace(int c)
{
	return ((9 <= c && c <= 13) || c == 32);
}

static long	ft_atol(const char *s)
{
	long	number;
	char	sign;

	number = 0;
	sign = 1;
	while (ft_isspace(*s))
		++s;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			sign = -1;
		++s;
	}
	while (ft_isdigit(*s))
		number = (number * 10) + (*(s++) - '0');
	return (number * sign);
}

static int	is_correct_format_number(const char *num)
{
	int	i;

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

t_i32_array	*parse_string_array(t_str_array *array)
{
	t_i32_array	*result;
	long		num;
	int			i;

	result = create_i32_array(array->len(array));
	if (!array->every(array, &is_correct_format_number))
		return (result->free(result), array->free(array), NULL);
	i = 0;
	while (i < result->size)
	{
		if ((*array->get(array, i) == '+' || *array->get(array, i) == '-')
			&& !array->get(array, i)[1])
		{
			(free(result), result = NULL);
			break ;
		}
		num = ft_atol(array->get(array, i));
		check_oob(num, array, result);
		result->list[i] = num;
		i++;
	}
	array->free(array);
	return (result);
}
