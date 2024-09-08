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
# include "../string_array/includes/string_array.h"
# include <limits.h>
# include <stdint.h>

typedef struct s_stack {
	unsigned int	size;
	unsigned int	len;
	int				*list;
}	t_stack;

// *** Error Handler *** //
int		check_stack(t_stack *stack);
void	*exit_if_null(void *ptr);


// *** Stack Functions *** //

int		compare_stacks(t_stack *stackA, t_stack *stackB);
void	free_stack(t_stack *stack);
t_stack *create_stack(unsigned int size, int *nums);
t_stack	*copy_stack(const t_stack *stack);
int		binary_search(int *arr, int size, int value);

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
void	rotate(t_stack *stack_a, t_stack *stack_b, int index_a, int print);

// *** Push_Swap  *** //

t_stack	*init_stack(int amount_of_nums);
t_stack	*tokenize_numbers(int argc, char **argv);
t_stack	*parse_numbers(t_stack *stack);
void	sort(t_stack *stack_a, t_stack *stack_b);

// *** Ordered *** //

int		is_ordered(const t_stack *stack);
int		is_partially_ordered(const t_stack *stack);
void	sort_partial_ordered_stack_a(t_stack *stack_a);
int		is_inversally_ordered(const t_stack *stack);
void	sort_inversally_ordered_stack_a(t_stack *stack_a, t_stack *stack_b);

// *** Sort *** //

void	sort(t_stack *stack_a, t_stack *stack_b);
void	sort3(t_stack *stack_a, t_stack *stack_b);
void	sort5(t_stack *stack_a, t_stack *stack_b);

// *** Heuristic *** //

int	greedy_algorithm(const t_stack *stack_a, const t_stack *stack_b);

// *** Main *** //

int		main(int argc, char **argv);

#endif /* PUSH_SWAP_H */
