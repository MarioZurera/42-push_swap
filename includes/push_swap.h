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

typedef struct s_stack	t_stack;

struct s_stack
{
	unsigned int	size;
	unsigned int	len;
	int				*list;
	void			(*free)(t_stack *);
	t_stack			*(*copy)(const t_stack *);
	int				(*cmp)(const t_stack *, const t_stack *);
	void			(*push)(t_stack *, int);
	void			(*push_back)(t_stack *, int);
	int				(*pop)(t_stack *);
	int				(*pop_back)(t_stack *);
	int				(*is_full)(const t_stack *);
	int				(*is_empty)(const t_stack *);
};

// *** Stack Functions *** //

t_stack	*create_stack(unsigned int size, int *nums);
t_stack	*create_stack_from(t_i32_array *array);

// *** Error Handler *** //
void	check_stack(t_stack *stack);
void	push_swap_error(void);

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
void	rotate(t_stack *stack_a, t_stack *stack_b, int index_b, int print);
int		get_rotations_cost(t_stack *stack_a, t_stack *stack_b, int index_b);
void	rotate_movements(t_stack *stack_a, t_stack *stack_b,
			int moves[2], int print);
void	rotate_a(t_stack *stack_a, int moves);

// *** Push_Swap  *** //

t_stack	*init_stack(int amount_of_nums);
t_stack	*tokenize_numbers(int argc, char **argv);
t_stack	*parse_numbers(t_stack *stack);
void	sort(t_stack *stack_a, t_stack *stack_b);
void	sort3(t_stack *stack);

// *** Ordered *** //

int		is_ordered(const t_stack *stack);
int		is_ordered_from(const t_stack *stack);
int		is_partially_ordered(const t_stack *stack);
void	sort_partial_ordered_stack_a(t_stack *stack_a);
int		is_inversally_ordered(const t_stack *stack);
void	sort_inversally_ordered_stack_a(t_stack *stack_a, t_stack *stack_b);

// *** Sort *** //

void	sort(t_stack *stack_a, t_stack *stack_b);
// void	sort5(t_stack *stack_a, t_stack *stack_b);

// *** Heuristic *** //

void	greedy_algorithm(t_stack *stack_a, t_stack *stack_b);
int		get_min_index(int *arr, int size);
void	set_sublen(int *current_length, int *max_length, int *end, int tmp_end);
void	push_to_b_tiny(t_stack *stack_a, t_stack *stack_b);

// *** Main *** //

int		main(int argc, char **argv);

#endif /* PUSH_SWAP_H */
