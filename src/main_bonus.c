/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 18:27:32 by mzurera-          #+#    #+#             */
/*   Updated: 2024/10/05 19:02:05 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	do_movements_2(t_stack *stack_a, t_stack *stack_b, char *movement)
{
	if (ft_strncmp(movement, "ra", 2) == 0)
		ra(stack_a, stack_b, 0);
	else if (ft_strncmp(movement, "rb", 2) == 0)
		rb(stack_a, stack_b, 0);
	else if (ft_strncmp(movement, "rra", 3) == 0)
		rra(stack_a, stack_b, 0);
	else if (ft_strncmp(movement, "rrb", 3) == 0)
		rrb(stack_a, stack_b, 0);
	else if (ft_strncmp(movement, "rrr", 3) == 0)
		rrr(stack_a, stack_b, 0);
	else if (ft_strncmp(movement, "rr", 2) == 0)
		rr(stack_a, stack_b, 0);
}

static void	do_movements(t_stack *stack_a, t_stack *stack_b)
{
	char	*movement;

	while (true)
	{
		movement = get_next_line(0);
		if (movement == NULL)
			break ;
		else if (ft_strncmp(movement, "sa", 2) == 0)
			sa(stack_a, stack_b, 0);
		else if (ft_strncmp(movement, "sb", 2) == 0)
			sb(stack_a, stack_b, 0);
		else if (ft_strncmp(movement, "ss", 2) == 0)
			ss(stack_a, stack_b, 0);
		else if (ft_strncmp(movement, "pa", 2) == 0)
			pa(stack_a, stack_b, 0);
		else if (ft_strncmp(movement, "pb", 2) == 0)
			pb(stack_a, stack_b, 0);
		do_movements_2(stack_a, stack_b, movement);
		free(movement);
	}
}

int	main(int argc, char **argv)
{
	t_stack		*stack_a;
	t_stack		*stack_b;

	stack_a = parse_numbers(tokenize_numbers(argc, argv));
	stack_b = create_stack(stack_a->size, NULL);
	do_movements(stack_a, stack_b);
	if (is_ordered(stack_a) && stack_b->len == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	stack_a->free(stack_a);
	stack_b->free(stack_b);
	return (0);
}
