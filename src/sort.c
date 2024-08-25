/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 01:46:01 by mzurera-          #+#    #+#             */
/*   Updated: 2024/08/02 23:42:51 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
static void	sort_3(t_stack *stack_a, t_stack *stack_b)
{
	sa(stack_a, stack_b);
	if (!is_ordered(stack_a))
		sort_partial_ordered_stack_a(stack_a);
}

void	sort(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a == NULL || stack_b == NULL || stack_b->len > 0)
		return ;
	if (is_ordered(stack_a))
		return ;
	if (is_partially_ordered(stack_a))
	{
		sort_partial_ordered_stack_a(stack_a);
		return ;
	}
	if (stack_a->len <= 3)
	{
		sort_3(stack_a, stack_b);
	}
}
*/

#include <stdio.h>

static void print_array(int nums[], unsigned int size)
{
	unsigned int i;
	for (i = 0; i < size; i++)
		printf("%d ", nums[i]);
	printf("\n");
}

static char	**sort_recursive(t_stack *stack_a, t_stack *stack_b, unsigned int limit);

static void	move(t_stack *stack_a, t_stack *stack_b, const char *movement)
{
	print_array(stack_a->list, stack_a->len);
	if (ft_strncmp(movement, "sa", 2) == 0)
		return (sa(stack_a, stack_b, 1));
	if (ft_strncmp(movement, "sb", 2) == 0)
		return (sb(stack_a, stack_b, 1));
	if (ft_strncmp(movement, "ss", 2) == 0)
		return (ss(stack_a, stack_b, 1));
	if (ft_strncmp(movement, "pa", 2) == 0)
		return (pa(stack_a, stack_b, 1));
	if (ft_strncmp(movement, "pb", 2) == 0)
		return (pb(stack_a, stack_b, 1));
	if (ft_strncmp(movement, "ra", 2) == 0)
		return (ra(stack_a, stack_b, 1));
	if (ft_strncmp(movement, "rb", 2) == 0)
		return (rb(stack_a, stack_b, 1));
	if (ft_strncmp(movement, "rr", 2) == 0)
		return (rr(stack_a, stack_b, 1));
	if (ft_strncmp(movement, "rra", 3) == 0)
		return (rra(stack_a, stack_b, 1));
	if (ft_strncmp(movement, "rrb", 3) == 0)
		return (rrb(stack_a, stack_b, 1));
	if (ft_strncmp(movement, "rrr", 3) == 0)
		return (rrr(stack_a, stack_b, 1));
}

static void	unmove(t_stack *stack_a, t_stack *stack_b, const char *movement)
{
	if (ft_strncmp(movement, "sa", 2) == 0)
		sa(stack_a, stack_b, 0);
	if (ft_strncmp(movement, "sb", 2) == 0)
		sb(stack_a, stack_b, 0);
	if (ft_strncmp(movement, "ss", 2) == 0)
		ss(stack_a, stack_b, 0);
	if (ft_strncmp(movement, "pa", 2) == 0)
		pb(stack_a, stack_b, 0);
	if (ft_strncmp(movement, "pb", 2) == 0)
		pa(stack_a, stack_b, 0);
	if (ft_strncmp(movement, "ra", 2) == 0)
		rra(stack_a, stack_b, 0);
	if (ft_strncmp(movement, "rb", 2) == 0)
		rrb(stack_a, stack_b, 0);
	if (ft_strncmp(movement, "rr", 2) == 0)
		rrr(stack_a, stack_b, 0);
	if (ft_strncmp(movement, "rra", 3) == 0)
		ra(stack_a, stack_b, 0);
	if (ft_strncmp(movement, "rrb", 3) == 0)
		rb(stack_a, stack_b, 0);
	if (ft_strncmp(movement, "rrr", 3) == 0)
		rr(stack_a, stack_b, 0);
}

static char	**process_movement(t_stack *stack_a, t_stack *stack_b, unsigned int limit, const char *movement)
{
	unsigned int	i;
	char			**result;
	char			 **strs;

	move(stack_a, stack_b, movement);
	result = sort_recursive(stack_a, stack_b, limit - 1);
	unmove(stack_a, stack_b, movement);
	if (result == NULL)
		return (NULL);
	i = 0;
	while (result[i] != NULL)
		i++;
	strs = malloc(sizeof(char *) * (i + 2));
	strs[0] = (char *) movement;
	ft_memcpy(strs + 1, result, (i + 1) * sizeof(char *));
	free(result);
	return (strs);
}

static char	**sort_recursive(t_stack *stack_a, t_stack *stack_b, unsigned int limit)
{
	char	**result;

	if (limit == 0)
		return (NULL);
	if (is_ordered(stack_a, stack_b))
	{
		result = malloc(sizeof(char *) * 1);
		result[0] = NULL;
		return (result);
	}
	result = process_movement(stack_a, stack_b, limit, "sa");
	if (result != NULL)
		return (result);
	result = process_movement(stack_a, stack_b, limit, "sb");
	if (result != NULL)
		return (result);
	result = process_movement(stack_a, stack_b, limit, "ss");
	if (result != NULL)
		return (result);
	result = process_movement(stack_a, stack_b, limit, "pa");
	if (result != NULL)
		return (result);
	result = process_movement(stack_a, stack_b, limit, "pb");
	if (result != NULL)
		return (result);
	result = process_movement(stack_a, stack_b, limit, "ra");
	if (result != NULL)
		return (result);
	result = process_movement(stack_a, stack_b, limit, "rb");
	if (result != NULL)
		return (result);
	result = process_movement(stack_a, stack_b, limit, "rr");
	if (result != NULL)
		return (result);
	result = process_movement(stack_a, stack_b, limit, "rra");
	if (result != NULL)
		return (result);
	result = process_movement(stack_a, stack_b, limit, "rrb");
	if (result != NULL)
		return (result);
	result = process_movement(stack_a, stack_b, limit, "rrr");
	if (result != NULL)
		return (result);
	return (NULL);
}

void	sort(t_stack *stack_a, t_stack *stack_b)
{
	unsigned int	i;
	char			**result;

	if (stack_a == NULL || stack_b == NULL || stack_b->len > 0)
		return ;
	result = sort_recursive(stack_a, stack_b, 4);
	i = 0;
	if (result == NULL)
		return ;
	while (result[i] != NULL)
		ft_printf("%s\n", result[i++]);
}