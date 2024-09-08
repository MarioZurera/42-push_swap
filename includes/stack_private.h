/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_private.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 01:24:28 by mzurera-          #+#    #+#             */
/*   Updated: 2024/08/03 20:20:42 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_PRIVATE_H
# define STACK_PRIVATE_H

# include "push_swap.h"

int		compare_stacks(const t_stack *stack_a, const t_stack *stack_b);
t_stack	*copy_stack(const t_stack *stack);
void	free_stack(t_stack *stack);
void	push_stack(t_stack *stack, int n);
void	push_back_stack(t_stack *stack, int n);
int		pop_stack(t_stack *stack);
int		pop_back_stack(t_stack *stack);
int		is_empty_stack(const t_stack *stack);
int		is_full_stack(const t_stack *stack);

t_stack	*create_stack_from(t_i32_array *array);
t_stack	*create_stack(const unsigned int size, int *nums);

#endif //STACK_PRIVATE_H
