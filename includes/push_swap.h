/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 01:24:28 by mzurera-          #+#    #+#             */
/*   Updated: 2024/08/03 20:20:42 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "../libft/colors.h"
# include <limits.h>
# include <stdbool.h>

typedef struct s_stack {
	unsigned int	size;
	unsigned int	len;
	int				*list;
}	t_stack;

// *** Stack Functions *** //

int		compare_stacks(t_stack *stackA, t_stack *stackB);
void	free_stack(t_stack *stack);
int		check_stack(t_stack *stack);
t_stack *create_stack(unsigned int size, int *nums);

// *** Movements *** //

int		sa(t_stack *stack_a, t_stack *stack_b, int print);
int		sb(t_stack *stack_a, t_stack *stack_b, int print);
int		ss(t_stack *stack_a, t_stack *stack_b, int print);
int		pa(t_stack *stack_a, t_stack *stack_b, int print);
int		pb(t_stack *stack_a, t_stack *stack_b, int print);
int		ra(t_stack *stack_a, t_stack *stack_b, int print);
int		rb(t_stack *stack_a, t_stack *stack_b, int print);
int		rr(t_stack *stack_a, t_stack *stack_b, int print);
int		rra(t_stack *stack_a, t_stack *stack_b, int print);
int		rrb(t_stack *stack_a, t_stack *stack_b, int print);
int		rrr(t_stack *stack_a, t_stack *stack_b, int print);

// *** Push_Swap  *** //

t_stack	*init_stack(int amount_of_nums);
t_stack	*tokenize_numbers(int argc, char **argv);
t_stack	*parse_numbers(t_stack *stack);

// *** Ordered *** //

int		is_ordered(const t_stack *stack);
int		is_partially_ordered(const t_stack *stack);
void	sort_partial_ordered_stack_a(t_stack *stack_a);

// *** Main *** //

int		main(int argc, char **argv);

#endif /* PUSH_SWAP_H */
