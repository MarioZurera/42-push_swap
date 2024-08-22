/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_testing.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 18:59:55 by mzurera-          #+#    #+#             */
/*   Updated: 2024/08/03 20:20:55 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_TESTING
# define PUSH_SWAP_TESTING

#include "../libft/libft.h"
#include "push_swap.h"

void	assert_stack(t_stack *stack_a, t_stack *stack_b);

void	test_string_parser(void);

void    test_list_parser(void);

#endif /* PUSH_SWAP_TESTING */
