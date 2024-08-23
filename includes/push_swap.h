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

typedef struct	s_stack
{
    unsigned int    size;
    int             *list;
}	t_stack;

typedef struct	s_pair {
    t_stack *stack_a;
    t_stack *stack_b;
} t_pair;

// *** Stack Functions *** //

int	    compare_stacks(t_stack *stackA, t_stack *stackB);
void	free_stack(t_stack *stack);
t_stack	*create_stack(unsigned int size, int *nums);

// *** Movements *** //

int sa(const t_pair *pair);
int sb(const t_pair *pair);
int ss(const t_pair *pair);
int	pa(const t_pair *pair);
int	pb(const t_pair *pair);

// *** Push_Swap  *** //

t_stack	*init_stack(int amount_of_nums);
void	free_stack(t_stack *stack);
int 	check_stack(t_stack *stack);
t_stack	*tokenize_numbers(int argc, char **argv);
t_stack *parse_numbers(t_stack *stack);

// *** Main *** //

int		main(int argc, char **argv);

#endif /* PUSH_SWAP_H */
