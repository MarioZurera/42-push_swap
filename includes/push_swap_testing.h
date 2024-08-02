/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_testing.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 18:59:55 by mzurera-          #+#    #+#             */
/*   Updated: 2024/08/02 20:34:42 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_TESTING
# define PUSH_SWAP_TESTING

#include "../libft/libft.h"
#include "push_swap.h"
#include "../testing/includes/ft_testing.h"

void	assert_stack(t_stack *stack_a, t_stack *stack_b);

void	test_string_parser(void);

void    test_list_parser(void);

#endif /* PUSH_SWAP_TESTING */